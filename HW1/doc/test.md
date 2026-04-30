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

IsEmpty：O(1)

NumberOfVertices：O(1)

NumberOfEdges：O(1)

Degree：O(1)

ExistsEdge：O(deg(u))

InsertVertex：O(n)

InsertEdge：O(1)

DeleteEdge：O(deg(u) + deg(v))

DeleteVertex：O(n + e)

showArraylist：O(n + e)

showMartix：O(n²)

### 空間複雜度

鄰接串列整體空間：O(n + e)

這種表示法比鄰接矩陣更省空間，特別適合邊數沒有很多的圖。

## 4.測試

### main()
```cpp
int main() {
    Graph g(10);

    g.InsertEdge(0, 1);
    g.InsertEdge(1, 2);
    g.InsertEdge(1, 3);
    g.InsertEdge(2, 4);
    g.InsertEdge(4, 3);
    g.InsertEdge(3, 5);
    g.InsertEdge(5, 6);
    g.InsertEdge(5, 7);
    g.InsertEdge(6, 7);
    g.InsertEdge(7, 8);
    g.InsertEdge(7, 9);

    cout << "IsEmpty: " << g.IsEmpty() << endl;
    cout << "NumberOfVertices: " << g.NumberOfVertices() << endl;
    cout << "NumberOfEdges: " << g.NumberOfEdges() << endl;
    cout << "Degree(7): " << g.Degree(7) << endl;
    cout << "ExistsEdge(5, 7): " << g.ExistsEdge(5, 7) << endl;

    g.showArraylist();
    g.showMartix();

    g.DeleteEdge(5, 7);
    g.DeleteVertex(9);

    cout << endl << "After DeleteEdge(5, 7) and DeleteVertex(9)" << endl;
    cout << "NumberOfVertices: " << g.NumberOfVertices() << endl;
    cout << "NumberOfEdges: " << g.NumberOfEdges() << endl;
    g.showArraylist();

    return 0;
}
```

### 輸出
```
IsEmpty: 0
NumberOfVertices: 10
NumberOfEdges: 11
Degree(7): 4
ExistsEdge(5, 7): 1
0 : 1 
1 : 0 2 3 
2 : 1 4 
3 : 1 4 5 
4 : 2 3 
5 : 3 6 7 
6 : 5 7 
7 : 5 6 8 9 
8 : 7 
9 : 7 
0 1 2 3 4 5 6 7 8 9 
0 1 0 0 0 0 0 0 0 0 
1 0 1 1 0 0 0 0 0 0 
0 1 0 0 1 0 0 0 0 0 
0 1 0 0 1 1 0 0 0 0 
0 0 1 1 0 0 0 0 0 0 
0 0 0 1 0 0 1 1 0 0 
0 0 0 0 0 1 0 1 0 0 
0 0 0 0 0 1 1 0 1 1 
0 0 0 0 0 0 0 1 0 0 
0 0 0 0 0 0 0 1 0 0 

After DeleteEdge(5, 7) and DeleteVertex(9)
NumberOfVertices: 9
NumberOfEdges: 9
0 : 1 
1 : 0 2 3 
2 : 1 4 
3 : 1 4 5 
4 : 2 3 
5 : 3 6 
6 : 5 7 
7 : 6 8 
8 : 7
```

## 5.心得討論

這次的圖形資料結構實作，讓我更熟悉鄰接串列的概念與無向圖的操作方式。
和單純只做新增邊相比，刪除頂點的處理更複雜，因為除了要移除相關邊之外，還要重新整理頂點編號，這部分讓我更理解資料結構維護時的細節。
透過這次練習，我也更清楚圖形結構中不同操作的成本差異。
例如查詢度數很快，但刪除頂點與輸出矩陣則需要較多時間。
