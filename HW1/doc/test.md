# HW3 Graph Abstract

## 1.解題說明

本程式主要是在實作一個圖形資料結構 Graph，並使用鄰接串列來儲存每個頂點之間的連結關係。
程式提供了圖的基本操作，包含判斷圖是否為空、查詢頂點數與邊數、計算頂點度數、確認邊是否存在，以及新增和刪除頂點、邊等功能。
另外也設計了兩種輸出方式，分別是鄰接串列與鄰接矩陣，方便觀察圖的結構是否正確。

這份程式的重點在於理解圖的基本操作與資料維護方式，尤其是無向圖在刪除頂點或刪除邊時，鄰接資料要如何同步更新，這是整個程式中最重要的部分。

### 基本操作
```cpp 
virtual ~Graph()
virtual bool IsEmpty()
virtual int NumberOfVertices()
virtual int NumberOfEdges()
virtual int Degree(int u)
virtual bool ExistsEdge(int u, int v)
virtual void InsertVertex(int v)
virtual void InsertEdge(int u, int v)
virtual void DeleteVertex(int v)
virtual void DeleteEdge(int u, int v)
```
宣告各種重載函式與Evaluate函式實現相關功能
## 2.演算法設計與實作

### operator' + '

```cpp
Polynomial operator+(const Polynomial& b) const {
    Polynomial result;
    Node* temp = result.head;

    Node* pa = this->head->link;
    Node* pb = b.head->link;

    while (pa != this->head && pb != b.head) {
        Node* newNode = new Node();
        if (pa->exp > pb->exp) {
            newNode->coef = pa->coef;
            newNode->exp = pa->exp;
            pa = pa->link;
        }
        else if (pa->exp < pb->exp) {
            newNode->coef = pb->coef;
            newNode->exp = pb->exp;
            pb = pb->link;
        }
        else {
            newNode->coef = pa->coef + pb->coef;
            newNode->exp = pa->exp;
            pa = pa->link;
            pb = pb->link;
        }
        temp->link = newNode;
        temp = temp->link;
    }

    while (pa != this->head) {
        Node* newNode = new Node();
        newNode->coef = pa->coef;
        newNode->exp = pa->exp;
        temp->link = newNode;
        temp = temp->link;
        pa = pa->link;
    }

    while (pb != b.head) {
        Node* newNode = new Node();
        newNode->coef = pb->coef;
        newNode->exp = pb->exp;
        temp->link = newNode;
        temp = temp->link;
        pb = pb->link;
    }

    temp->link = result.head;  // 將最後一個節點鏈結到頭節點
    return result;
}
```

### operator' - '

```cpp
Polynomial Polynomial::Mult(const Polynomial& poly) const {
    Polynomial result;
    result.capacity = terms * poly.terms;
    result.termArray = new Term[result.capacity];

    for (int i = 0; i < terms; ++i) {
        for (int j = 0; j < poly.terms; ++j) {
            float newCoef = termArray[i].coef * poly.termArray[j].coef;
            int newExp = termArray[i].exp + poly.termArray[j].exp;
            bool found = false;

            for (int k = 0; k < result.terms; ++k) {
                if (result.termArray[k].exp == newExp) {
                    result.termArray[k].coef += newCoef;
                    found = true;
                    break;
                }
            }

            if (!found) {
                result.termArray[result.terms].coef = newCoef;
                result.termArray[result.terms].exp = newExp;
                result.terms++;
            }
        }
    }

    // 移除係數為0的項次
    int validTerms = 0;
    for (int i = 0; i < result.terms; ++i) {
        if (result.termArray[i].coef != 0) {
            result.termArray[validTerms++] = result.termArray[i];
        }
    }
    result.terms = validTerms;

    return result;
}
```

### operator' * '

```cpp
Polynomial operator*(const Polynomial& b) const {
        Polynomial result;
        Node* pa = this->head->link;

        while (pa != this->head) {
            Polynomial tempPoly;
            Node* temp = tempPoly.head;
            Node* pb = b.head->link;

            while (pb != b.head) {
                Node* newNode = new Node();
                newNode->coef = pa->coef * pb->coef;  // 係數相乘
                newNode->exp = pa->exp + pb->exp;    // 指數相加
                temp->link = newNode;
                temp = temp->link;
                pb = pb->link;
            }

            temp->link = tempPoly.head;  // 將最後一個節點鏈結到頭節點
            result = result + tempPoly;
            pa = pa->link;
        }

        return result;
}
```

## 3.效能分析

### 時間複雜度

輸入 (operator>>): O( $n$ )

輸出 (operator<<): O( $n$ )

加法 (operator+) 和 減法 (operator-): O( $n1+n2$ )

乘法 (operator*): O( $n1 \times n2$ )

Eval: O( $n$ )

### 空間複雜度

輸入 (operator>>): O( $n$ )

輸出 (operator<<): O( $1$ )

加法 (operator+) 和 減法 (operator-): O( $n1+n2$ )

乘法 (operator*): O( $n1 \times n2$ )

Eval: O( $1$ )
## 4.測試

```
請輸入多項式 p1: 3 5 3 4 2 3 0
請輸入多項式 p2: 3 2 5 8 3 2 2
p1 + p2 = 2x^5 + 13x^3 + 6x^2 + 3x^0
p1 - p2 = -2x^5 + -3x^3 + 2x^2 + 3x^0
p1 * p2 = 10x^8 + 8x^7 + 40x^6 + 48x^5 + 8x^4 + 24x^3 + 6x^2
請輸入要計算的 x 值: 5
p1(x) = 728
p2(x) = 7300
```

## 5.心得討論

因為上次有用陣列方式實作過了多項式的各種算術操作，這次就是把程式碼本來用陣列的方式改成使用串列連結的方式，並且重載每個算術的符號，這次
比較特別的是要新增一個減法功能，這是上次也沒有做過的。但有了前一次自我打好基礎後，我感覺在打code的時候健步如飛，比上次工作速度還要快上
許多，真的非常有感。
