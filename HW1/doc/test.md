# Minimum Spanning Tree

## 1.解題說明

Minimum Spanning Tree (MST) 是在一個加權無向圖中，
找出一棵包含所有頂點且總權重最小的生成樹。

本題實作兩種經典演算法：

- Kruskal：依邊權重由小到大選擇邊
- Prim：從起點開始逐步擴張生成樹

兩種方法皆能得到最小生成樹，但實作方式不同。

---

## 2.演算法設計與實作

### Edge 結構

```cpp
struct Edge {
    int u;
    int v;
    int weight;
};
```

### Disjoint Set（Union-Find）

```cpp
class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int Find(int x) {
        if (parent[x] != x) {
            parent[x] = Find(parent[x]);
        }
        return parent[x];
    }

    bool Union(int x, int y) {
        int rootX = Find(x);
        int rootY = Find(y);

        if (rootX == rootY) return false;

        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            ++rank[rootX];
        }

        return true;
    }
};
```

### Graph Representation（Adjacency List）

```cpp
vector<pair<int,int>>* adj;
vector<Edge> edges;
```

### InsertEdge

```cpp
void InsertEdge(int u, int v, int weight) {
    adj[u].push_back({v, weight});
    adj[v].push_back({u, weight});
    edges.push_back({u, v, weight});
}
```

### Kruskal

```cpp
void Kruskal() {
    vector<Edge> sortedEdges = edges;
    sort(sortedEdges.begin(), sortedEdges.end(), compareEdge);

    DisjointSet ds(n);
    int totalWeight = 0;

    for (Edge edge : sortedEdges) {
        if (ds.Union(edge.u, edge.v)) {
            totalWeight += edge.weight;
        }
    }
}
```

### Prim

```cpp
void Prim(int start) {
    vector<bool> visited(n, false);

    priority_queue<Edge, vector<Edge>, decltype(cmp)> pq(cmp);

    visited[start] = true;

    for (auto neighbor : adj[start]) {
        pq.push({start, neighbor.first, neighbor.second});
    }

    int totalWeight = 0;

    while (!pq.empty()) {
        Edge edge = pq.top();
        pq.pop();

        if (visited[edge.v]) continue;

        visited[edge.v] = true;
        totalWeight += edge.weight;

        for (auto neighbor : adj[edge.v]) {
            if (!visited[neighbor.first]) {
                pq.push({edge.v, neighbor.first, neighbor.second});
            }
        }
    }
}
```

## 3.效能分析

### 時間複雜度

Kruskal：O(E log E)

Prim：O(E log V)

Union-Find（Find / Union）：接近 O(1)

InsertEdge：O(1)

### 空間複雜度

Adjacency List：O(n + e)

Edge List：O(e)

Priority Queue（Prim）：O(e)

Disjoint Set：O(n)

## 4.測試

```cpp
int main() {
    Graph g(7);

    g.InsertEdge(0, 1, 7);
    g.InsertEdge(0, 3, 5);
    g.InsertEdge(1, 2, 8);
    g.InsertEdge(1, 3, 9);
    g.InsertEdge(1, 4, 7);
    g.InsertEdge(2, 4, 5);
    g.InsertEdge(3, 4, 15);
    g.InsertEdge(3, 5, 6);
    g.InsertEdge(4, 5, 8);
    g.InsertEdge(4, 6, 9);
    g.InsertEdge(5, 6, 11);

    cout << "Adjacency List:" << endl;
    g.showArraylist();

    cout << endl;

    g.Kruskal();

    cout << endl;

    g.Prim(0);

    return 0;
}
```

### 輸出

```
Adjacency List:
0 : (1, 7) (3, 5) 
1 : (0, 7) (2, 8) (3, 9) (4, 7) 
2 : (1, 8) (4, 5) 
3 : (0, 5) (1, 9) (4, 15) (5, 6) 
4 : (1, 7) (2, 5) (3, 15) (5, 8) (6, 9) 
5 : (3, 6) (4, 8) (6, 11) 
6 : (4, 9) (5, 11) 

Kruskal's Algorithm:
MST Edges:
0 - 3 : 5
2 - 4 : 5
3 - 5 : 6
0 - 1 : 7
1 - 4 : 7
4 - 6 : 9
Total Weight: 39

Prim's Algorithm:
Start Vertex: 0
MST Edges:
0 - 3 : 5
3 - 5 : 6
0 - 1 : 7
1 - 4 : 7
4 - 2 : 5
4 - 6 : 9
Total Weight: 39
```

## 5.心得討論
一開始看到 MST 其實有點搞不太懂在幹嘛，但寫完之後發現其實就是一直選最小的邊而已。
Kruskal 寫起來比較直覺，就是排序邊然後一條一條加，但要小心 cycle，所以 Union-Find 一開始有點難理解。
Prim 的話一開始比較難想，但其實就是從一個點開始慢慢擴展，用 priority queue 去找最小邊，寫完之後覺得滿酷的。
實際寫過之後才發現，兩個演算法雖然結果一樣，但思路真的差很多。
