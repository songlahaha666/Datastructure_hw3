# 41143138
# 41143111

---

## 專案介紹

本專案使用 C++ 實作多種排序演算法，並針對不同資料規模進行 Benchmark 測試與效能分析。

實作內容包含：

- Insertion Sort
- Merge Sort
- Quick Sort
- Heap Sort
- Composite Sort

此外，本專案亦包含：

- 測資生成器（Test Data Generator）
- Average Case Benchmark
- Worst Case Benchmark
- Composite Sort Range Benchmark
- CSV 結果輸出
- 圖表分析

---

## 解題說明

### 題目需求

本次作業要求實作多種排序演算法，並分析其：

- Worst Case Runtime
- Average Runtime
- Time Complexity
- Space Complexity

此外，也需要：

- 產生測試資料
- 計算執行時間
- 分析不同演算法效能差異
- 建立 Composite Function
- 輸出 Benchmark 結果

---

### 解題策略

本專案主要使用：

- Divide and Conquer
- Heap Structure
- In-place Sorting
- Hybrid Sorting

等方式完成排序功能。

在 Benchmark 部分，使用：

```cpp
std::chrono::high_resolution_clock
```

進行時間量測。

為降低量測誤差，使用 repeated benchmark 與總時間平均方式進行分析。

---

### Sorting Algorithms

#### Worst Case Data Design

本專案針對四種排序法設計或近似產生 Worst Case 測資。由於不同排序法造成最差情況的原因不同，因此沒有使用同一組資料套用到全部演算法，而是依照各排序法的特性分別產生測資。

#### Insertion Sort Worst Case

Insertion Sort 的最差情況發生在資料完全反序時。

原因是 Insertion Sort 會從左到右逐一將元素插入前面已排序區間中，若輸入資料為由大到小排列，則每次新元素都必須一路往前比較並移動到最前面，造成最多次的比較與搬移。

因此本專案使用 `generateReverseData(n)` 產生 Insertion Sort 的 Worst Case 測資。

範例：

```text
n = 5
Worst Case Data = [5, 4, 3, 2, 1]
```

---

#### Merge Sort Worst Case

Merge Sort 的時間複雜度雖然固定為 O(n log n)，但不同資料排列仍會影響每次 merge 時的比較次數。

Merge Sort 的 Worst Case 目標是讓左右兩個已排序子陣列在合併時盡量交錯，使 merge 過程需要進行較多比較。

本專案使用 generateMergeWorstCaseData(n) 產生 Merge Sort 的 Worst Case 測資。其概念是從排序完成後的結果反推，先將已排序資料依照索引奇偶位置拆成左右兩半，再對左右兩半遞迴執行相同拆分，最後將左右結果接回。

這樣可以讓 Merge Sort 在合併時，左右子陣列的元素盡量交錯出現，增加 merge 階段的比較次數。

範例：

```text
Sorted Data = [1, 2, 3, 4, 5, 6, 7, 8]

拆分：
Left  = [1, 3, 5, 7]
Right = [2, 4, 6, 8]

再遞迴拆分左右兩邊，最後組合成 Merge Sort Worst Case Data。
```

---

#### Quick Sort Worst Case & Heap Sort Worst Case

Quick Sort 的最差情況通常發生在每次選到的 pivot 都無法有效將資料平均分割時。

例如當資料已排序或反序，且 pivot 選擇方式固定為第一個或最後一個元素時，每次 partition 都可能只切出一邊幾乎沒有資料、另一邊包含剩餘大部分資料，導致遞迴深度增加，時間複雜度退化為 O(n²)。

Heap Sort 的 Worst Case 較不容易像 Insertion Sort 一樣直接用完全反序資料建立，因為 Heap Sort 的主要成本來自於建堆與每次刪除最大值後的 heapify 過程，而不同排列造成的實際執行時間差異不像 Insertion Sort 或 Quick Sort 那麼直觀。

不過本專案在 Worst Case Benchmark 中，對 Quick Sort & Heap Sort  採用 random permutation generator 產生大量隨機排列，最後取其中執行時間最大的結果作為 Worst Case Approximation。

也就是說，本專案並非直接使用固定的已排序或反序資料作為 Worst Case，而是透過多次隨機排列測試，取得其中執行時間最長的一次作為近似最差情況。

---


### Composite Sort
本專案在 Merge Sort 的小區間中改用 Insertion Sort。

原因為：

- 小型資料遞迴成本較高
- Insertion Sort 在小區間效率較佳
- 可以降低 recursive overhead

因此在小型子陣列時切換至 Insertion Sort，可有效提升整體效能。

---

### Average Test Data Generation

本專案使用隨機排列（Random Permutation）產生測試資料。

Average Case 測試中：

- 每筆資料只使用一次
- 計算整體執行時間

Worst Case 測試中：

- 使用特定排列方式建立 Worst Case Data

---

## 程式實作

### 專案架構

```text
SortingProject
├── include
│   ├── benchmark.h
│   ├── data_generator.h
│   └── sorting.h
│
├── src
│   ├── insertion_sort.cpp
│   ├── merge_sort.cpp
│   ├── quick_sort.cpp
│   ├── heap_sort.cpp
│   ├── composite_sort.cpp
│   ├── benchmark.cpp
│   ├── average_case_benchmark.cpp
│   ├── worst_case_benchmark.cpp
│   ├── composite_benchmark.cpp
│   ├── data_generator.cpp
│   └── main.cpp
│
└── result
    ├── average_case_result.csv
    ├── worst_case_result.csv
    ├── composite_case_result.csv
    └── worst_case_result(500~5000).csv
```

---

### Benchmark 流程

```text
Generate Test Data
        ↓
Copy Array
        ↓
Run Sorting Algorithm
        ↓
Measure Execution Time
        ↓
Store Result
        ↓
Output CSV
```

---

### Compile Command

```shell
$ g++ src/*.cpp -std=c++21 -o sorting.exe
$ ./sorting.exe
```

---

### CSV Output

Benchmark 結果會輸出成 CSV 檔案，方便後續：

- Excel 分析
- 圖表建立
- Runtime 比較

---

## 效能分析

### Time Complexity

| Algorithm | Best Case | Average Case | Worst Case |
|---|---|---|---|
| Insertion Sort | O(n) | O(n²) | O(n²) |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) |
| Quick Sort | O(n log n) | O(n log n) | O(n²) |
| Heap Sort | O(n log n) | O(n log n) | O(n log n) |
| Composite Sort | O(n log n) | O(n log n) | O(n log n) |

---

### Space Complexity

| Algorithm | Space Complexity |
|---|---|
| Insertion Sort | O(1) |
| Merge Sort | O(n) |
| Quick Sort | O(log n) |
| Heap Sort | O(1) |
| Composite Sort | O(n) |

---

### Composite Sort Analysis

Composite Sort 在小型資料區間中改用 Insertion Sort。

原因為：

- Merge Sort 遞迴成本較高
- 小區間 Merge 成本較大
- Insertion Sort 在小資料效率較佳

因此 Hybrid 方法能有效提升實際執行效率。

---

## 測試與驗證

### Clock Accuracy

本專案使用：

```cpp
std::chrono::high_resolution_clock
```

作為時間量測工具。

其精度可達 nanoseconds 等級。

由於單次排序時間可能過短，因此透過 repeated benchmark 與總時間平均方式降低量測誤差。

---

### Average Case Benchmark

Average Case 使用 Random Permutation 進行測試。

每個資料大小皆產生多組隨機排列資料，並計算其總執行時間。

#### Average Case Result

```md
![Average Case Graph](images/average_case.png)
```

#### Average Case Table

| n | insertion | merge | quick | heap |
|---|---|---|---|---|
| TODO | TODO | TODO | TODO | TODO |

---

### Worst Case Benchmark

Worst Case 測試使用特定排列方式建立 Worst Case Data。

#### Worst Case Result

```md
![Worst Case Graph](images/worst_case.png)
```

#### Worst Case Table

| n | insertion | merge | quick | heap |
|---|---|---|---|---|
| TODO | TODO | TODO | TODO | TODO |

---

### Narrowed Range Benchmark

為了更清楚觀察演算法效能變化，本專案進一步縮小 n 的範圍進行測試。

#### Narrowed Range Result

```md
![Narrowed Range Graph](images/narrowed_range.png)
```

---

### Composite Benchmark

本專案另外測試 Composite Sort 與一般 Merge Sort 的效能差異。

#### Composite Benchmark Result

```md
![Composite Graph](images/composite.png)
```

#### Composite Benchmark Table

| threshold | runtime |
|---|---|
| TODO | TODO |

---

### Benchmark Analysis

根據實驗結果可以觀察到：

- Insertion Sort 在大型資料時效率較差
- Merge Sort 與 Heap Sort 在大型資料較穩定
- Quick Sort 在特定 Worst Case 下會退化
- Composite Sort 在小區間具有較佳效能

---

## 申論及開發報告

### 使用 Merge Sort 的原因

Merge Sort 的時間複雜度穩定為 O(n log n)，因此適合大型資料排序。

此外，其 Divide and Conquer 架構也較容易進行 Hybrid 擴充。

---

### 使用 Insertion Sort 的原因

Insertion Sort 雖然 Worst Case 為 O(n²)，但在小型資料中具有良好效能。

因此適合作為 Composite Sort 的小區間排序方法。

---

### 使用 Heap Sort 的原因

Heap Sort 不需要額外大量記憶體空間，且 Worst Case 時間複雜度穩定。

因此適合用來比較不同排序方法在 Worst Case 下的表現。

---

### 使用 CSV 輸出的原因

CSV 格式方便：

- 後續資料分析
- Excel 建立圖表
- Runtime 比較

因此本專案將 Benchmark 結果輸出成 CSV 檔案。

---

### 使用 Random Permutation 的原因

Average Case Data 難以人工建立，因此使用 Random Permutation 模擬一般情況下的輸入資料。

---

## 7. 結論

本專案成功完成：

- 多種 Sorting Algorithms
- Benchmark System
- Worst Case Analysis
- Average Case Analysis
- Composite Sort Analysis

實驗結果顯示：

- O(n²) 演算法不適合大型資料
- O(n log n) 演算法較穩定
- Hybrid Sorting 可有效提升實際效能

透過本次作業，也更加了解不同排序演算法的特性與適用情境。

---

## 8. 附錄

### 8.2 Result CSV

（請附上 Benchmark CSV 檔案）
