# HW3 Graph Operations
## 1. 解題說明

本程式實作一個無向圖資料結構 `Graph`，使用鄰接串列（vector 陣列）儲存每個頂點的鄰接清單。
功能包含基本圖操作（新增邊）、圖的走訪（DFS、BFS）、圖分析（Connected Components、Biconnected Components）以及輸出輔助函式（列印鄰接串列）。

### 設計目標：
- 練習圖的鄰接串列實作與動態記憶體管理
- 實作 DFS 與 BFS 走訪
- 利用 DFS 延伸實作 Connected Components（連通分量）
- 使用 Tarjan-like 演算法找 Biconnected Components（雙連通分量，基於邊）

## 2. 程式設計與實作

### 主要檔案：`GraphOperations.cpp`
核心資料成員：
- `n`：頂點數
- `adj`：`vector<int>*`，長度為 `n`，每個元素為該頂點的鄰接清單
- `visited`：走訪標記陣列
- `dfn`, `low`, `timeCounter`, `stack<Edge>`：用於 Biconnected 演算法

### 主要方法摘要（與範例程式片段）

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


## 3. 效能分析

時間複雜度（以 n 頂點、e 邊計）：
- InsertEdge：O(1)
- DFS（整圖）：O(n + e)
- BFS（整圖）：O(n + e)
- ConnectedComponents：O(n + e)
- Biconnected（Tarjan）：O(n + e)
- 輸出鄰接串列：O(n + e)
- 輸出鄰接矩陣（若實作）：O(n^2)

空間複雜度：
- 鄰接串列：O(n + e)
- 額外：`visited`、`dfn`、`low` 等為 O(n)，stack 為 O(e) worst-case。

## 4. 測試（main 範例）

程式 `main()` 會建立一個 12 頂點的圖並插入幾條邊（包含一個獨立小分量 10-11），然後依序輸出：

- 鄰接串列（Adjacency List）
- DFS（從 0 與從 2）
- BFS（從 0 與從 2）
- Connected Components（節點集合）
- Biconnected Components（以邊列出，程式目前輸出邊對）

程式執行範例輸出（節錄）：
```
Adjacency List:
0 : 1 2
1 : 0 3 4
...
DFS starting from vertex 0:
0 1 3 7 4 8 2 5 6 9
BFS starting from vertex 0:
0 1 2 3 4 5 6 7 8 9
Connected Components:
Component 1: 0 1 3 7 4 8 2 5 6 9
Component 2: 10 11
Biconnected Components (edge-based):
New Biconnected Component:
3 7
New Biconnected Component:
1 3
...
```

## 6. 心得與擴充建議

本次實作讓我熟悉鄰接串列表示法，以及 DFS/BFS 在圖上的典型用途。
並且更加了解Connected Components以及Biconnected Components之間的實作差異，透過先前的GraphAbstract又延伸出了各種Graph操作，
把這些結合起來成就了一個基本的程式框架。
