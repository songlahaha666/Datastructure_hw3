# 41143138
# 41143111 
- `result/average_case_result.csv`

## 專案介紹
本專案為資料結構 Homework 2 作業，使用 C++ 實作 Graph（圖形）相關資料結構與演算法。

內容包含圖形表示法、圖形走訪、最小生成樹、最短路徑以及活動網路等主題。
<br>
<br>

## 功能內容

### Graph Abstract Data Type（圖形抽象資料型態）
- Adjacency Matrix（鄰接矩陣）
- Linked Adjacency Lists（鏈結式鄰接串列）
- Array Adjacency Lists（陣列式鄰接串列）
- Directed Graph（有向圖）
- Undirected Graph（無向圖）
- Weighted Graph（加權圖）
- Unweighted Graph（非加權圖）
- Insert Vertex（插入頂點）
- Insert Edge（插入邊）
- Delete Vertex（刪除頂點）
- Delete Edge（刪除邊）
- Edge Existence Check（邊存在檢查）
- Number of Vertices（頂點數量）
- Number of Edges（邊數量）

### Elementary Graph Operations（圖形基本操作）
- Depth First Search（DFS 深度優先搜尋）
- Breadth First Search（BFS 廣度優先搜尋）
- Connected Components（連通元件）
- Biconnected Components（雙連通元件）

### Minimum Cost Spanning Trees（最小生成樹）
- Kruskal’s Algorithm
- Prim’s Algorithm

### Shortest Paths and Transitive Closure（最短路徑）
- Single Source Shortest Path（單源最短路徑）
- All-Pairs Shortest Paths（全點對最短路徑）

### Activity Networks（活動網路）
- Activity on Vertex（AOV 網路）
- Activity on Edge（AOE 網路）

### Test Data Generator (測資生成)
- 自動生成 Graph 測資
- 支援 Directed/Undirected (有向/無向)
- 支援 Weighted/Unweighted (加權/非加權)

### Benchmark（效能測試）
- 自動生成測資並測試演算法
- 支援不同規模測試：
  - 10,000 edges
  - 100,000 edges
  - 1,000,000 edges
- 顯示不同演算法執行時間
- 驗證資料規模（edge 數量輸出）
---

<br>
<br>

## 開發環境

### 軟體環境
- C++
- Visual Studio Code
- g++
- GitHub

### 硬體設備
- Windows 11
- 處理器	Intel(R) Core(TM) i5-14400F   2.50 GHz
- 已安裝記憶體(RAM)	32.0 GB
- 儲存體	1.86 TB SSD XPG GAMMIX S70 BLADE
- 顯示卡	NVIDIA GeForce RTX 4070 (12 GB)
- 系統類型	64 位元作業系統，x64 型處理器

---

<br>
<br>

## 編譯方式

使用 g++ 編譯 C++ 程式。


```bash
g++ *.cpp -o output
```
### 🔹 編譯與執行方式

本程式於 Windows 環境下，使用 g++ 編譯器進行編譯，並透過命令列執行。

```shell
$ g++ main.cpp -std=c++21 -o main.exe
$ ./main.exe
```

上述指令會將程式編譯為執行檔 main.exe，並執行程式輸出結果。

ex:
g++ GraphAbstract/src/GraphAbstract.cpp -o GraphAbstract/bin/GraphAbstract.exe
./GraphAbstract/bin/GraphAbstract.exe

---


<br>
<br>

## 解題說明

### Graph Abstract

本程式主要是在實作一個圖形資料結構 Graph，並使用鄰接串列來儲存每個頂點之間的連結關係。
程式提供了圖的基本操作，包含判斷圖是否為空、查詢頂點數與邊數、計算頂點度數、確認邊是否存在，以及新增和刪除頂點、邊等功能。
另外也設計了兩種輸出方式，分別是鄰接串列與鄰接矩陣，方便觀察圖的結構是否正確。

這份程式的重點在於理解圖的基本操作與資料維護方式，尤其是無向圖在刪除頂點或刪除邊時，鄰接資料要如何同步更新，這是整個程式中最重要的部分。

### Graph Operations

本程式實作一個無向圖資料結構 `Graph`，使用鄰接串列（vector 陣列）儲存每個頂點的鄰接清單。
功能包含基本圖操作（新增邊）、圖的走訪（DFS、BFS）、圖分析（Connected Components、Biconnected Components）以及輸出輔助函式（列印鄰接串列）。

### Minimum Spanning Tree

Minimum Spanning Tree (MST) 是在一個加權無向圖中，
找出一棵包含所有頂點且總權重最小的生成樹。

本題實作兩種經典演算法：

- Kruskal：依邊權重由小到大選擇邊
- Prim：從起點開始逐步擴張生成樹

兩種方法皆能得到最小生成樹，但實作方式不同。

### Shortest Path

Shortest Path 是用來找出圖中兩個頂點之間最短距離的問題。

本題實作三種最短路徑演算法：

- Dijkstra：適用於非負權重的單源最短路徑
- Bellman-Ford：可以處理負權重的單源最短路徑
- Floyd-Warshall：可以計算所有點對之間的最短路徑

本題使用加權有向圖作為主要測試資料，並分別針對不同演算法設計適合的測試圖。

### Activity Network

Activity Network 是用來描述一組具有先後順序的活動，
常用於專案排程分析。

本題實作兩個重要演算法：

- Topological Sort：找出事件的執行順序
- Critical Path Method (CPM)：找出關鍵路徑與專案最短完成時間

圖的表示方式為加權有向圖（Directed Weighted Graph），
其中：

- 頂點代表事件
- 邊代表活動
- 權重代表活動所需時間

### Benchmark

本實驗目的是透過大量圖形測資，
比較不同圖論演算法在實際執行時的效能差異。

測試內容涵蓋本次作業中所有主要演算法，
並使用相同規模的資料進行測試，以確保公平性。

測試規模包含：

- 10,000 edges
- 100,000 edges
- 1,000,000 edges

透過這些測試，可以觀察不同演算法在資料量增加時的表現變化。

<br>
<br>

## 程式實作

### Graph Abstract

#### 基本操作
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
#### IsEmpty

```cpp
virtual bool IsEmpty() const {
        return n == 0;
    }
```

#### NumberOfVertices

```cpp
virtual int NumberOfVertices() const {
        return n;
    }  
```

#### NumberOfEdges

```cpp
virtual int NumberOfEdges() const {
        return e;
    }
```

#### Degree

```cpp
virtual int Degree(int u) const {
        if (!isValidVertex(u)) {
            return 0;
        }
        return static_cast<int>(adj[u].size());
    }
```

#### ExistsEdge

```cpp
virtual bool ExistsEdge(int u, int v) const {
        if (!isValidVertex(u) || !isValidVertex(v)) {
            return false;
        }
        return find(adj[u].begin(), adj[u].end(), v) != adj[u].end();
    }
```

#### InsertVertex

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

#### InsertEdge

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

#### DeleteVertex

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

#### DeleteEdge

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

#### showMartix

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

#### showArraylist

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

<br>

### Graph Operations

#### 主要檔案：`GraphOperations.cpp`
核心資料成員：
- `n`：頂點數
- `adj`：`vector<int>*`，長度為 `n`，每個元素為該頂點的鄰接清單
- `visited`：走訪標記陣列
- `dfn`, `low`, `timeCounter`, `stack<Edge>`：用於 Biconnected 演算法

#### 主要方法摘要（與範例程式片段）

- InsertEdge(u, v) — 新增無向邊（在 u 與 v 的鄰接清單各加入對方）
```cpp
void InsertEdge(int u, int v) {
    if (!isValidVertex(u) || !isValidVertex(v)) return;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
```

- DFS (遞迴) — 深度優先走訪（Driver: 會先把 visited 清為 false 再從指定頂點遞迴）
```cpp
void DFS(int v) {
    visited[v] = true;
    cout << v << ' ';
    for (int w : adj[v]) if (!visited[w]) DFS(w);
}
```

- BFS — 廣度優先走訪（使用 queue）
```cpp
void BFS(int v) {
    fill visited false; queue<int> q;
    visited[v]=true; q.push(v);
    while(!q.empty()){
      int cur=q.front(); q.pop(); cout<<cur<<' ';
      for(int w: adj[cur]) if(!visited[w]){ visited[w]=true; q.push(w); }
    }
}
```

- ConnectedComponents — 使用多次 DFS 找所有連通分量
```cpp
void ConnectedComponents() {
    fill visited false;
    for (i=0..n-1) if(!visited[i]) {
        vector<int> comp; DFSCollect(i, comp);
        // 輸出 comp
    }
}
```

- Biconnected（邊為單位的雙連通分量）
核心遞迴函式 BiconnectedRec：
```cpp
void BiconnectedRec(int u, int parent) {
    dfn[u] = low[u] = ++timeCounter;
    for (int w : adj[u]) {
        if (w == parent) continue;
        if (dfn[w] == 0) {
            s.push({u,w});
            BiconnectedRec(w,u);
            low[u] = min(low[u], low[w]);
            if (low[w] >= dfn[u]) {
                // pop edges until (u,w), 輸出為一個 biconnected component (edge-based)
            }
        } else if (dfn[w] < dfn[u]) {
            s.push({u,w});
            low[u] = min(low[u], dfn[w]);
        }
    }
}
```

<br>

### Minimum Spanning Tree

#### Edge 結構

```cpp
struct Edge {
    int u;
    int v;
    int weight;
};
```

#### Disjoint Set（Union-Find）

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


#### Graph Representation（Adjacency List）

```cpp
vector<pair<int,int>>* adj;
vector<Edge> edges;
```

#### InsertEdge

```cpp
void InsertEdge(int u, int v, int weight) {
    adj[u].push_back({v, weight});
    adj[v].push_back({u, weight});
    edges.push_back({u, v, weight});
}
```

#### Kruskal

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

#### Prim

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
<br>

### Shortest Path

#### Edge 結構

```cpp
struct Edge {
    int u;
    int v;
    int weight;
};
```

#### Graph Representation（Adjacency List）

```cpp
vector<pair<int, int>>* adj;
vector<Edge> edges;
```

#### InsertDirectedEdge

```cpp
void InsertDirectedEdge(int u, int v, int weight) {
    if (!isValidVertex(u) || !isValidVertex(v)) {
        return;
    }

    adj[u].push_back({v, weight});
    edges.push_back({u, v, weight});
    ++e;

    sort(adj[u].begin(), adj[u].end());
}
```

#### InsertUndirectedEdge

```cpp
void InsertUndirectedEdge(int u, int v, int weight) {
    if (!isValidVertex(u) || !isValidVertex(v)) {
        return;
    }

    InsertDirectedEdge(u, v, weight);
    InsertDirectedEdge(v, u, weight);
}
```

#### Dijkstra

```cpp
void Dijkstra(int source) {
    if (!isValidVertex(source)) {
        return;
    }

    vector<int> dist(n, INF);
    vector<bool> visited(n, false);

    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int currentDistance = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) {
            continue;
        }

        visited[u] = true;

        for (auto neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (!visited[v] && dist[v] > currentDistance + weight) {
                dist[v] = currentDistance + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Dijkstra Algorithm:" << endl;
    showDistance(dist, source);
}
```

#### Bellman-Ford

```cpp
void BellmanFord(int source) {
    if (!isValidVertex(source)) {
        return;
    }

    vector<int> dist(n, INF);
    dist[source] = 0;

    for (int i = 1; i <= n - 1; ++i) {
        for (Edge edge : edges) {
            if (dist[edge.u] < INF &&
                dist[edge.v] > dist[edge.u] + edge.weight) {
                dist[edge.v] = dist[edge.u] + edge.weight;
            }
        }
    }

    bool hasNegativeCycle = false;

    for (Edge edge : edges) {
        if (dist[edge.u] < INF &&
            dist[edge.v] > dist[edge.u] + edge.weight) {
            hasNegativeCycle = true;
            break;
        }
    }

    cout << "Bellman-Ford Algorithm:" << endl;

    if (hasNegativeCycle) {
        cout << "Negative weight cycle detected." << endl;
        return;
    }

    showDistance(dist, source);
}
```

#### Floyd-Warshall

```cpp
void FloydWarshall() {
    vector<vector<int>> dist(n, vector<int>(n, INF));

    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }

    for (int u = 0; u < n; ++u) {
        for (auto neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            dist[u][v] = min(dist[u][v], weight);
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF &&
                    dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    cout << "Floyd-Warshall Algorithm:" << endl;
    cout << "All-Pairs Shortest Paths:" << endl;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] >= INF) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
}
```

<br>

### Activity Network

#### Edge 結構

```cpp
struct Edge {
    int u;
    int v;
    int weight;
};
```

#### Graph Representation（Adjacency List）

```cpp
vector<pair<int, int>>* adj;
vector<Edge> edges;
```

#### InsertEdge

```cpp
void InsertEdge(int u, int v, int weight) {
    if (!isValidVertex(u) || !isValidVertex(v)) {
        return;
    }

    adj[u].push_back({v, weight});
    edges.push_back({u, v, weight});

    sort(adj[u].begin(), adj[u].end());
}
```

#### Topological Sort（Kahn's Algorithm）

```cpp
bool TopologicalSort(vector<int>& topoOrder) {
    vector<int> indegree(n, 0);

    for (int u = 0; u < n; ++u) {
        for (auto neighbor : adj[u]) {
            int v = neighbor.first;
            indegree[v]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < n; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        topoOrder.push_back(u);

        for (auto neighbor : adj[u]) {
            int v = neighbor.first;
            indegree[v]--;

            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    return static_cast<int>(topoOrder.size()) == n;
}
```

#### Critical Path

```cpp
void CriticalPath() {
    vector<int> topoOrder;

    if (!TopologicalSort(topoOrder)) {
        cout << "此圖不是 DAG，無法進行 Critical Path 分析。" << endl;
        return;
    }

    vector<int> ve(n, 0);

    for (int u : topoOrder) {
        for (auto neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            ve[v] = max(ve[v], ve[u] + weight);
        }
    }

    vector<int> vl(n, ve[topoOrder.back()]);

    for (int i = n - 1; i >= 0; --i) {
        int u = topoOrder[i];

        for (auto neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            vl[u] = min(vl[u], vl[v] - weight);
        }
    }

    for (Edge edge : edges) {
        int e = ve[edge.u];
        int l = vl[edge.v] - edge.weight;

        if (e == l) {
            cout << edge.u << " -> " << edge.v << endl;
        }
    }
}
```
<br>

### Benchmark

本實驗撰寫一個 Benchmark 程式，
負責以下流程：

1. 使用 TestDataGenerator 產生隨機加權圖
2. 建立 adjacency list 作為圖的表示方式
3. 呼叫各演算法進行運算
4. 使用 `chrono` 計算執行時間

主要測試演算法如下：

#### GraphOperations
- DFS
- BFS
- Connected Components

#### MinimumSpanningTree
- Kruskal
- Prim

#### ShortestPath
- Dijkstra
- Bellman-Ford

#### ActivityNetwork
- Topological Sort
- Critical Path（僅功能展示）


<br>
<br>

## 效能分析

### Graph Abstract

#### 時間複雜度

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

#### 空間複雜度

鄰接串列整體空間：O(n + e)

這種表示法比鄰接矩陣更省空間，特別適合邊數沒有很多的圖。
<br>
<br>

### Graph Operations

#### 時間複雜度

- InsertEdge：O(1)
- DFS（整圖）：O(n + e)
- BFS（整圖）：O(n + e)
- ConnectedComponents：O(n + e)
- Biconnected（Tarjan）：O(n + e)
- 輸出鄰接串列：O(n + e)
- 輸出鄰接矩陣（若實作）：O(n^2)

#### 空間複雜度

- 鄰接串列：O(n + e)
- 額外：`visited`、`dfn`、`low` 等為 O(n)，stack 為 O(e) worst-case。
  
  <br>
  <br>

### Minimum Spanning Tree

#### 時間複雜度

Kruskal：O(E log E)

Prim：O(E log V)

Union-Find（Find / Union）：接近 O(1)

InsertEdge：O(1)

#### 空間複雜度

Adjacency List：O(n + e)

Edge List：O(e)

Priority Queue（Prim）：O(e)

Disjoint Set：O(n)
<br>
<br>

### Shortest Path

#### 時間複雜度

InsertDirectedEdge：O(deg(u) log deg(u))

InsertUndirectedEdge：O(deg(u) log deg(u) + deg(v) log deg(v))

Dijkstra：O((n + e) log n)

Bellman-Ford：O(n × e)

Floyd-Warshall：O(n³)

showArraylist：O(n + e)

showDistance：O(n)

#### 空間複雜度

Adjacency List：O(n + e)

Edge List：O(e)

Dijkstra Distance Array：O(n)

Dijkstra Priority Queue：O(e)

Bellman-Ford Distance Array：O(n)

Floyd-Warshall Matrix：O(n²)

本題主要使用 adjacency list 儲存圖，可以有效節省空間。
Floyd-Warshall 則使用 matrix 計算所有點對最短路徑，因此空間需求較高。
<br>
<br>

### Activity Network

#### 時間複雜度

InsertEdge：O(deg(u) log deg(u))

TopologicalSort：O(n + e)

CriticalPath：O(n + e)

showArraylist：O(n + e)

#### 空間複雜度

Adjacency List：O(n + e)

Edge List：O(e)

Topological Order：O(n)

ve / vl 陣列：O(n)
<br>

### Benchmark

#### 時間複雜度

DFS：O(n + e)

BFS：O(n + e)

Connected Components：O(n + e)

Kruskal：O(e log e)

Prim：O(e log n)

Dijkstra：O(e log n)

Bellman-Ford：O(n × e)

Topological Sort：O(n + e)

Critical Path：O(n + e)

#### 空間複雜度

Adjacency List：O(n + e)

Edge List：O(e)

Priority Queue：O(e)

Distance / visited 陣列：O(n)

<br>
<br>

## 測試與驗證

### Graph Abstract

#### 程式的輸入
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

#### 輸出
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
<br>

### Graph Operations

#### 4. 程式的輸入

程式 `main()` 會建立一個 12 頂點的圖並插入幾條邊（包含一個獨立小分量 10-11），然後依序輸出：

- 鄰接串列（Adjacency List）
- DFS（從 0 與從 2）
- BFS（從 0 與從 2）
- Connected Components（節點集合）
- Biconnected Components（以邊列出，程式目前輸出邊對）
```cpp
int main() {
    Graph g(12);

    g.InsertEdge(0, 1);
    g.InsertEdge(0, 2);
    g.InsertEdge(1, 3);
    g.InsertEdge(1, 4);
    g.InsertEdge(2, 5);
    g.InsertEdge(2, 6);
    g.InsertEdge(3, 7);
    g.InsertEdge(4, 8);
    g.InsertEdge(6, 9);
    g.InsertEdge(10, 11);

    cout << "Adjacency List:" << endl;
    g.showArraylist();

    cout << "DFS starting from vertex 0:" << endl;
    g.DFS();

    cout << "DFS starting from vertex 2:" << endl;
    g.DFSFrom(2);

    cout << "BFS starting from vertex 0:" << endl;
    g.BFS(0);

    cout << "BFS starting from vertex 2:" << endl;
    g.BFS(2);

    cout << "Connected Components:" << endl;
    g.ConnectedComponents();

    cout << "Biconnected Components (edge-based):" << endl;
    g.Biconnected();

    return 0;
}
```

#### 輸出
```
Adjacency List:
0 : 1 2 
1 : 0 3 4 
2 : 0 5 6 
3 : 1 7 
4 : 1 8 
5 : 2 
6 : 2 9 
7 : 3 
8 : 4 
9 : 6 
10 : 11 
11 : 10 
DFS starting from vertex 0:
0 1 3 7 4 8 2 5 6 9 
DFS starting from vertex 2:
2 0 1 3 7 4 8 5 6 9 
BFS starting from vertex 0:
0 1 2 3 4 5 6 7 8 9 
BFS starting from vertex 2:
2 0 5 6 1 9 3 4 7 8 
Connected Components:
Component 1: 0 1 3 7 4 8 2 5 6 9 
Component 2: 10 11 
Biconnected Components (edge-based):
New Biconnected Component:
3 7
New Biconnected Component:
1 3
New Biconnected Component:
4 8
New Biconnected Component:
1 4
New Biconnected Component:
0 1
New Biconnected Component:
2 5
New Biconnected Component:
6 9
New Biconnected Component:
2 6
New Biconnected Component:
0 2
New Biconnected Component:
10 11
```
<br>

### Minimum Spanning Tree

#### 4.程式的輸入

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

#### 輸出

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
<br>

### Shortest Path

#### 4.程式的輸入

```cpp
int main() {
    Graph g(5);

    g.InsertDirectedEdge(0, 1, 6);
    g.InsertDirectedEdge(0, 2, 7);
    g.InsertDirectedEdge(1, 2, 8);
    g.InsertDirectedEdge(1, 3, 5);
    g.InsertDirectedEdge(1, 4, -4);
    g.InsertDirectedEdge(2, 3, -3);
    g.InsertDirectedEdge(2, 4, 9);
    g.InsertDirectedEdge(3, 1, -2);
    g.InsertDirectedEdge(4, 0, 2);
    g.InsertDirectedEdge(4, 3, 7);

    cout << "Adjacency List:" << endl;
    g.showArraylist();

    cout << endl;

    g.BellmanFord(0);

    cout << endl;

    g.FloydWarshall();

    cout << endl;

    Graph positiveGraph(5);

    positiveGraph.InsertDirectedEdge(0, 1, 10);
    positiveGraph.InsertDirectedEdge(0, 3, 5);
    positiveGraph.InsertDirectedEdge(1, 2, 1);
    positiveGraph.InsertDirectedEdge(1, 3, 2);
    positiveGraph.InsertDirectedEdge(2, 4, 4);
    positiveGraph.InsertDirectedEdge(3, 1, 3);
    positiveGraph.InsertDirectedEdge(3, 2, 9);
    positiveGraph.InsertDirectedEdge(3, 4, 2);
    positiveGraph.InsertDirectedEdge(4, 0, 7);
    positiveGraph.InsertDirectedEdge(4, 2, 6);

    cout << "Positive Weighted Graph:" << endl;
    positiveGraph.showArraylist();

    cout << endl;

    positiveGraph.Dijkstra(0);

    return 0;
}
```

#### 輸出

```
Adjacency List:
0 : (1, 6) (2, 7) 
1 : (2, 8) (3, 5) (4, -4) 
2 : (3, -3) (4, 9) 
3 : (1, -2) 
4 : (0, 2) (3, 7) 

Bellman-Ford Algorithm:
Source Vertex: 0
Distance from 0 to 0 : 0
Distance from 0 to 1 : 2
Distance from 0 to 2 : 7
Distance from 0 to 3 : 4
Distance from 0 to 4 : -2

Floyd-Warshall Algorithm:
All-Pairs Shortest Paths:
0 2 7 4 -2 
-2 0 5 2 -4 
-7 -5 0 -3 -9 
-4 -2 3 0 -6 
2 4 9 6 0 

Positive Weighted Graph:
0 : (1, 10) (3, 5) 
1 : (2, 1) (3, 2) 
2 : (4, 4) 
3 : (1, 3) (2, 9) (4, 2) 
4 : (0, 7) (2, 6) 

Dijkstra Algorithm:
Source Vertex: 0
Distance from 0 to 0 : 0
Distance from 0 to 1 : 8
Distance from 0 to 2 : 9
Distance from 0 to 3 : 5
Distance from 0 to 4 : 7
```
<br>

### Activity Network

#### 4.程式的輸入

```cpp
int main() {
    Graph g(9);

    g.InsertEdge(0, 1, 6);
    g.InsertEdge(0, 2, 4);
    g.InsertEdge(0, 3, 5);

    g.InsertEdge(1, 4, 1);
    g.InsertEdge(2, 4, 1);
    g.InsertEdge(3, 5, 2);

    g.InsertEdge(4, 6, 9);
    g.InsertEdge(4, 7, 7);

    g.InsertEdge(5, 7, 4);

    g.InsertEdge(6, 8, 2);
    g.InsertEdge(7, 8, 4);

    g.showArraylist();

    g.CriticalPath();

    return 0;
}
```

#### 輸出

```
==================================
Activity Network
==================================

鄰接串列 (Adjacency List)
0 : (1, 6) (2, 4) (3, 5) 
1 : (4, 1) 
2 : (4, 1) 
3 : (5, 2) 
4 : (6, 9) (7, 7) 
5 : (7, 4) 
6 : (8, 2) 
7 : (8, 4) 
8 : 

==============================
Activity Network 分析結果
==============================

拓樸排序 (Topological Order)
0 1 2 3 4 5 6 7 8 

最早事件時間 (ve)
Vertex 0 : 0
Vertex 1 : 6
Vertex 2 : 4
Vertex 3 : 5
Vertex 4 : 7
Vertex 5 : 7
Vertex 6 : 16
Vertex 7 : 14
Vertex 8 : 18

最晚事件時間 (vl)
Vertex 0 : 0
Vertex 1 : 6
Vertex 2 : 6
Vertex 3 : 8
Vertex 4 : 7
Vertex 5 : 10
Vertex 6 : 16
Vertex 7 : 14
Vertex 8 : 18

Critical Activities
0 -> 1 (Duration: 6)
1 -> 4 (Duration: 1)
4 -> 6 (Duration: 9)
4 -> 7 (Duration: 7)
6 -> 8 (Duration: 2)
7 -> 8 (Duration: 4)

專案最短完成時間：18
```
<br>

### Benchmark

#### 4.程式的輸入
本實驗透過程式自動生成測資，
並執行各演算法進行測試。

為確保測資正確，
程式會輸出實際生成的邊數：

```cpp
cout << "Generated Edges: " << edges.size() << endl;
```
用來確認生成資料與預期一致。<br>

測試過程中，
透過 chrono 計算各演算法的執行時間，
並觀察不同規模下的變化。

```cpp
int main() {
    TestDataGenerator generator;

    cout << "======================================" << endl;
    cout << "Weighted Directed Graph" << endl;
    cout << "======================================" << endl;

    vector<Edge> weightedDirected =
        generator.GenerateWeightedDirectedGraph(
            10,
            20,
            1,
            100
        );

    generator.ShowEdges(weightedDirected);

    cout << endl << endl;

    cout << "======================================" << endl;
    cout << "Weighted Undirected Graph" << endl;
    cout << "======================================" << endl;

    vector<Edge> weightedUndirected =
        generator.GenerateWeightedUndirectedGraph(
            10,
            20,
            1,
            100
        );

    generator.ShowEdges(weightedUndirected);

    cout << endl << endl;

    cout << "======================================" << endl;
    cout << "Unweighted Directed Graph" << endl;
    cout << "======================================" << endl;

    vector<Edge> unweightedDirected =
        generator.GenerateUnweightedDirectedGraph(
            10,
            20
        );

    generator.ShowEdges(unweightedDirected);

    cout << endl << endl;

    cout << "======================================" << endl;
    cout << "Unweighted Undirected Graph" << endl;
    cout << "======================================" << endl;

    vector<Edge> unweightedUndirected =
        generator.GenerateUnweightedUndirectedGraph(
            10,
            20
        );

    generator.ShowEdges(unweightedUndirected);

    return 0;
}

```

#### 輸出

##### 10,000 edges
```
Select Benchmark Size
1. 10,000 edges
2. 100,000 edges
3. 1,000,000 edges
Enter choice: 1

======================================
Benchmark Start
======================================
Vertex Count: 1000
Requested Edges: 10000

Generating test data...
Generated Edges: 10000
Generate Time: 0.0087899 seconds

Building graph...
Build Graph Time: 0.0024578 seconds

======================================
Homework 1 - GraphAbstract
======================================
InsertEdge Time: 0.0010987 seconds
ExistsEdge Time: 6e-07 seconds

======================================
Homework 2 - GraphOperations
======================================
DFS Time: 0.0009804 seconds
BFS Time: 0.0004689 seconds
Connected Components Time: 0.000463 seconds
Biconnected Components:
Not suitable for large-scale benchmark.

======================================
Homework 3 - MinimumSpanningTree
======================================
Kruskal Total Weight: 6665
Kruskal Time: 0.0021243 seconds
Prim Total Weight: 6665
Prim Time: 0.002231 seconds

======================================
Homework 4 - ShortestPath
======================================
Dijkstra Time: 0.001433 seconds
Bellman-Ford Time: 0.110783 seconds
Floyd-Warshall:
Not suitable for large-scale benchmark.

======================================
Homework 5 - ActivityNetwork
======================================
Topological Sort:
Not suitable for large-scale benchmark.

Critical Path:
Not suitable for large-scale benchmark.

Benchmark Finished
```

##### 100,000 edges
```
Select Benchmark Size
1. 10,000 edges
2. 100,000 edges
3. 1,000,000 edges
Enter choice: 2

======================================
Benchmark Start
======================================
Vertex Count: 10000
Requested Edges: 100000

Generating test data...
Generated Edges: 100000
Generate Time: 0.101098 seconds

Building graph...
Build Graph Time: 0.0206667 seconds

======================================
Homework 1 - GraphAbstract
======================================
InsertEdge Time: 0.0112204 seconds
ExistsEdge Time: 1e-06 seconds

======================================
Homework 2 - GraphOperations
======================================
DFS Time: 0.008501 seconds
BFS Time: 0.003334 seconds
Connected Components Time: 0.0031307 seconds
Biconnected Components:
Not suitable for large-scale benchmark.

======================================
Homework 3 - MinimumSpanningTree
======================================
Kruskal Total Weight: 66441
Kruskal Time: 0.0202752 seconds
Prim Total Weight: 66441
Prim Time: 0.0213643 seconds

======================================
Homework 4 - ShortestPath
======================================
Dijkstra Time: 0.0113344 seconds
Bellman-Ford Time: 9.22818 seconds
Floyd-Warshall:
Not suitable for large-scale benchmark.

======================================
Homework 5 - ActivityNetwork
======================================
Topological Sort:
Not suitable for large-scale benchmark.

Critical Path:
Not suitable for large-scale benchmark.

Benchmark Finished
```

##### 1,000,000 edges
```
Select Benchmark Size
1. 10,000 edges
2. 100,000 edges
3. 1,000,000 edges
Enter choice: 3

======================================
Benchmark Start
======================================
Vertex Count: 100000
Requested Edges: 1000000

Generating test data...
Generated Edges: 1000000
Generate Time: 1.37173 seconds

Building graph...
Build Graph Time: 0.210383 seconds

======================================
Homework 1 - GraphAbstract
======================================
InsertEdge Time: 0.0969528 seconds
ExistsEdge Time: 1e-06 seconds

======================================
Homework 2 - GraphOperations
======================================
DFS Time: 0.0715711 seconds
BFS Time: 0.0262365 seconds
Connected Components Time: 0.036574 seconds
Biconnected Components:
Not suitable for large-scale benchmark.

======================================
Homework 3 - MinimumSpanningTree
======================================
Kruskal Total Weight: 80817
Kruskal Time: 0.219223 seconds
Prim Total Weight: 80817
Prim Time: 0.345554 seconds

======================================
Homework 4 - ShortestPath
======================================
Dijkstra Time: 0.0715787 seconds
Bellman-Ford Time: 824.295 seconds
Floyd-Warshall:
Not suitable for large-scale benchmark.

======================================
Homework 5 - ActivityNetwork
======================================
Topological Sort:
Not suitable for large-scale benchmark.

Critical Path:
Not suitable for large-scale benchmark.

Benchmark Finished
```

<br>
<br>

## 申論及開發報告
<br>

### Graph Abstract

這次主要是用**鄰接串列**來存儲圖的資料，之所以選擇它是因為相比鄰接矩陣省超多空間。如果用矩陣的話，就算圖的邊數很少，也得開闢 O(n²) 的空間浪費，但鄰接串列只需要 O(n + e) 就夠了，特別是對邊數不多的圖來說真的划算。在實作上，我用了動態陣列來管理每個頂點的相鄰列表，雖然新增邊很簡單，但刪除頂點就麻煩了，因為要重新編號所有受影響的頂點，得產生一個新的動態陣列同時更新所有的關係。

在設計各個操作的時間複雜度時也有不少考量。像是 `IsEmpty`、`NumberOfVertices` 和 NumberOfEdges 都做成 O(1)，因為它們只是簡單地回傳預先維護的變數就行，不用每次都重新計算。但 ExistsEdge 就要 O(deg(u)) 了，因為得在頂點 u 的相鄰列表中線性搜尋，相比用矩陣能達到 O(1) 的速度，這裡是為了省空間而犧牲一點查詢速度。而 DeleteVertex 是最複雜的，需要 O(n + e) 的時間，因為不只要移除邊，還得重建整個圖；相比之下 DeleteEdge 就簡單得多，只需要 O(deg(u) + deg(v))，在兩個頂點的列表中各移除一次就完事了。

透過這次實作，我真的體會到資料結構的選擇有多重要。不同的結構在空間和時間上的權衡都不一樣，得根據實際應用需求來決定什麼才是最合適的。這次也讓我明白，看似簡單的操作背後其實有超多細節——像是刪除頂點時要同時維護相鄰列表和頂點編號，這些小地方要是沒處理好就很容易出 bug，而我現在對這些細節的理解也更深入了。

<br>

### Graph Operations

在演算法設計上，DFS 和 BFS 都做成 O(n + e) 的複雜度，因為就是把每個頂點和每條邊訪問一遍而已。Connected Components 是利用多次 DFS 來找所有連通分量，邏輯其實不會很複雜，就是用 DFS 把一個連通分量的節點都標記起來，然後再對沒訪問過的頂點重複做同樣的事。Biconnected Components 就比較麻煩了，用的是 Tarjan-like 演算法搭配 stack，要追蹤每個邊什麼時候應該被 pop 出來，這部分的細節得想清楚才行。

透過這次實作，我真的體會到圖的各種演算法之間的連結。從基本的走訪開始，慢慢延伸出更複雜的操作，像是從 DFS 就能推展出 Connected Components，再進一步做到 Biconnected Components，這種遞進的學習方式讓我對圖論的理解更深入了。而且把這些操作組合起來，就構成了一個完整的圖操作框架，這也讓我看到了模組化設計的重要性。
<br>

### Minimum Spanning Tree

本作業需找出最小生成樹（Minimum Spanning Tree），即在不形成環的情況下，選擇總權重最小的邊集合，使所有頂點連通。

此問題適合使用 Kruskal 與 Prim 演算法，原因如下：

1. 最小生成樹問題本質為在所有邊中選擇適當子集合，並避免形成環
2. Kruskal 演算法透過排序所有邊，並使用 Union-Find 判斷是否形成環，能有效建立最小生成樹
3. Prim 演算法則從任一頂點出發，透過逐步擴展的方式建立生成樹

資料結構方面：
- Kruskal 使用 Union-Find（Disjoint Set）處理連通性
- Prim 使用 Priority Queue（最小堆）選擇最小邊

因此，兩種演算法皆為解決最小生成樹問題的標準方法，並適用於不同圖形特性。
<br>

### Shortest Path

本作業需解決單源最短路徑問題，即從一個起點計算到所有其他頂點的最短距離。

此問題適合使用 Dijkstra 與 Bellman-Ford 演算法，原因如下：

1. Dijkstra 演算法適用於所有邊權重皆為非負的圖，能有效計算最短路徑，時間複雜度為 O(E log V)
2. Bellman-Ford 演算法可處理含負權重邊的圖，並能檢測是否存在負環（Negative Cycle）
3. 兩種演算法分別對應不同條件的最短路徑問題

資料結構方面：
- Dijkstra 使用 Priority Queue（最小堆）
- Bellman-Ford 使用 Edge List 進行鬆弛操作

因此，本作業採用兩種演算法，以完整涵蓋最短路徑問題的不同情境。
<br>

### Activity Network

本作業需處理活動網路問題，包含任務排序與專案時間分析。

此問題適合使用 Topological Sort 與 Critical Path Method，原因如下：

1. 活動網路通常為有向無環圖（DAG），拓樸排序可用於找出合法的任務執行順序
2. Topological Sort 能確保所有依賴關係被正確滿足
3. Critical Path Method 用於找出從起點到終點的最長路徑，該路徑決定整體專案完成時間

資料結構方面：
- 使用鄰接串列表示 DAG
- 使用 Queue 實作 Kahn’s Algorithm（拓樸排序）
- 使用陣列儲存最早時間與最晚時間

因此，這些演算法能有效應用於專案排程與時間管理問題。
<br>

### Benchmark

在本次實驗中，
可以明顯觀察不同演算法在大規模資料下的差異。

#### 設定

- 圖形類型：無向加權圖
- 測資來源：隨機生成
- 測試規模：
  - 10,000 edges
  - 100,000 edges
  - 1,000,000 edges

---

#### 基本資訊

| 邊數 (Edges) | 頂點數 (Vertices) | 生成時間 (s) | 建圖時間 (s) |
|-------------|------------------|-------------|-------------|
| 10,000 | 1,000 | 0.0087899 | 0.0024578 |
| 100,000 | 10,000 | 0.101098 | 0.0206667 |
| 1,000,000 | 100,000 | 1.37173 | 0.210383 |

---

#### 圖形操作 (Graph Operations)

| 邊數 | DFS (s) | BFS (s) | 連通元件 (s) |
|------|--------|--------|-------------|
| 10,000 | 0.0009804 | 0.0004689 | 0.000463 |
| 100,000 | 0.008501 | 0.003334 | 0.0031307 |
| 1,000,000 | 0.0715711 | 0.0262365 | 0.036574 |

---

#### 最小生成樹 (MST)

| 邊數 | Kruskal (s) | Prim (s) |
|------|------------|----------|
| 10,000 | 0.0021243 | 0.002231 |
| 100,000 | 0.0202752 | 0.0213643 |
| 1,000,000 | 0.219223 | 0.345554 |

---

#### 最短路徑 (Shortest Path)

| 邊數 | Dijkstra (s) | Bellman-Ford (s) |
|------|-------------|------------------|
| 10,000 | 0.001433 | 0.110783 |
| 100,000 | 0.0113344 | 9.22818 |
| 1,000,000 | 0.0715787 | 824.295 |

---

#### DFS 與 BFS

- 兩者時間皆隨資料量線性成長
- BFS 在所有測試中略快於 DFS

原因：
- DFS 使用遞迴或 stack，有額外呼叫成本
- BFS 使用 queue，執行較穩定

結論：
> DFS 與 BFS 均為 O(V + E)，但 BFS 實務上略快

---

#### Kruskal 與 Prim

- 小規模時差異不大
- 大規模時 Kruskal 明顯較快

原因：
- Kruskal：排序一次 + Union-Find
- Prim：頻繁操作 Priority Queue（log V）

結論：
> 邊數多時，Kruskal 效能較佳

---

#### Dijkstra 與 Bellman-Ford

- Dijkstra 表現穩定
- Bellman-Ford 在大規模資料下效能急遽下降

原因：
- Dijkstra：O(E log V)
- Bellman-Ford：O(V × E)

結論：
> Bellman-Ford 不適合大型圖，僅用於負權邊情境

---

#### 不適合大型圖的演算法

- Floyd-Warshall（O(V³)）
- Biconnected Components
- Topological Sort（需 DAG）
- Critical Path（需 DAG）

---
- DFS / BFS / Connected Components 具良好擴展性
- Kruskal 在大規模圖中優於 Prim

## 圖表（Benchmark Plots）

以下為本次執行的 benchmark 產生之圖表（位於 `result/plots/`）：

- Composite — Average Case

![composite average](result/plots/composite_average.png)

- Composite — Worst Case

![composite worst](result/plots/composite_worst.png)

- Average Case (overall)

![average case](result/plots/average_case.png)

- Worst Case (overall)

![worst case](result/plots/worst_case.png)

原始測量資料（CSV）位於 `result/`：

- [result/average_case_result.csv](result/average_case_result.csv)
- [result/worst_case_result.csv](result/worst_case_result.csv)
- [result/composite_case_result.csv](result/composite_case_result.csv)

如需我將圖表嵌入 PDF 或優化圖表（例如使用對數刻度、標註交叉點），我可以繼續處理。
- Dijkstra 為實務首選最短路徑演算法
- Bellman-Ford 在大型圖中不具實用性

---

DFS、BFS、Connected Components 等演算法，
由於時間複雜度為 O(n + e)，
在資料量增加時仍能維持穩定表現。

Kruskal 與 Prim 表現也相當穩定，
但仍受到排序與 priority queue 操作影響。

Dijkstra 在非負權重圖中效率良好，
是實務上常用的最短路徑演算法。

Bellman-Ford 則在資料規模增加時明顯變慢，
在 1,000,000 edges 測試中，
執行時間遠高於其他演算法，
顯示其 O(n × e) 的時間複雜度影響非常明顯。

在開發過程中也遇到一些問題：

Bellman-Ford 在大資料下執行時間過長
Floyd-Warshall 因為 O(n³) 無法應用在大規模測試
Activity Network 必須為 DAG 才能正確執行

透過這次 Benchmark，
不只是驗證演算法正確性，
也更清楚理解不同演算法在實際應用上的差異，
以及選擇合適演算法的重要性。
