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
## 2.演算法設計與實作

### IsEmpty

```cpp
virtual bool IsEmpty() const {
        return n == 0;
    }
```

### NumberOfVertices

```cpp
virtual int NumberOfVertices() const {
        return n;
    }  
```

### NumberOfEdges

```cpp
virtual int NumberOfEdges() const {
        return e;
    }
```

### Degree

```cpp
virtual int Degree(int u) const {
        if (!isValidVertex(u)) {
            return 0;
        }
        return static_cast<int>(adj[u].size());
    }
```

### ExistsEdge

```cpp
virtual bool ExistsEdge(int u, int v) const {
        if (!isValidVertex(u) || !isValidVertex(v)) {
            return false;
        }
        return find(adj[u].begin(), adj[u].end(), v) != adj[u].end();
    }
```

### InsertVertex

```cpp
virtual void InsertVertex(int v) {
        (void)v;
        vector<int>* newAdj = new vector<int>[n + 1];
        for (int i = 0; i < n; ++i) {
            newAdj[i] = adj[i];
        }
        delete[] adj;
        adj = newAdj;
        ++n;
    }
```

### InsertEdge

```cpp
virtual void InsertEdge(int u, int v) {
        if (!isValidVertex(u) || !isValidVertex(v) || ExistsEdge(u, v)) {
            return;
        }
        adj[u].push_back(v);
        adj[v].push_back(u);
        ++e;
    }
```

### DeleteVertex

```cpp
virtual void DeleteVertex(int v) {
        if (!isValidVertex(v)) {
            return;
        }

        vector<int>* newAdj = new vector<int>[n - 1];
        for (int i = 0, newIndex = 0; i < n; ++i) {
            if (i == v) {
                continue;
            }

            for (int neighbor : adj[i]) {
                if (neighbor == v) {
                    continue;
                }

                if (neighbor > v) {
                    newAdj[newIndex].push_back(neighbor - 1);
                } else {
                    newAdj[newIndex].push_back(neighbor);
                }
            }

            ++newIndex;
        }

        delete[] adj;
        adj = newAdj;
        --n;

        int edgeCount = 0;
        for (int i = 0; i < n; ++i) {
            edgeCount += static_cast<int>(adj[i].size());
        }
        e = edgeCount / 2;
    }
```

### DeleteEdge

```cpp
virtual void DeleteEdge(int u, int v) {
        if (!isValidVertex(u) || !isValidVertex(v) || !ExistsEdge(u, v)) {
            return;
        }

        bool removedFromU = removeNeighbor(u, v);
        bool removedFromV = removeNeighbor(v, u);
        if (removedFromU && removedFromV) {
            --e;
        }
    }
```

### showMartix

```cpp
void showMartix() {
        for (int k = 0; k < n; k++) {
            cout << k << " ";
        }
        cout << endl;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; j++) {
                if (ExistsEdge(i, j)) {
                    cout << "1 ";
                } else {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }
```

### showArraylist

```cpp
void showArraylist() {
        vector<int>::iterator it;
        for (int i = 0; i < n; ++i) {
            cout << i << " : ";
            for (it = adj[i].begin(); it != adj[i].end(); ++it)
                cout << *it << " ";
            cout << endl;
        }
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
