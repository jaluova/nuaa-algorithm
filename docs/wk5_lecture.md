# 算法第5周讲义：分治法 — 快速幂、选择问题与划分

---

## 一、整数幂计算（快速幂）

### 1.1 问题

计算 $x^n$，其中 $n$ 为正整数。朴素做法需要 $n-1$ 次乘法，能否更快？

### 1.2 二分幂（Binary Exponentiation）

将 $n$ 表示为二进制 $n = (b_k b_{k-1} \cdots b_1 b_0)_2$，则：

$$x^n = x^{b_k 2^k} \cdot x^{b_{k-1} 2^{k-1}} \cdots x^{b_0 2^0}$$

其中 $x^{2^i}$ 可以通过反复平方得到：$x \to x^2 \to x^4 \to x^8 \to \cdots$

### 1.3 两种迭代实现

**方法一（从高到低）**：

```
y ← 1
for i ← k down to 0:
    if b_i = 1:
        y ← y × x
    x ← x × x               // 平方
return y
```

**方法二（从低到高，更直观）**：

```
p ← x                       // p = x^{2^i}，从 x^{2^0} 开始
y ← 1
while n > 0:
    if n mod 2 = 1:         // 当前二进制位为 1
        y ← y × p
    p ← p × p               // p = x^{2^{i+1}}
    n ← n / 2
return y
```

### 1.4 复杂度

乘法次数 $\Theta(\log n)$，比朴素 $O(n)$ 有数量级优势。

---

## 二、分治法概述

### 2.1 设计范式

**分治法**：将一个问题拆成若干个规模更小的子问题，递归求解后合并结果。

对比**归纳法**：将问题变成比它更小的一个问题来求解。

### 2.2 三步框架

1. **分解（Divide）**：将原问题分解为若干子问题
2. **治理（Conquer）**：递归求解各子问题
3. **合并（Combine）**：将子问题的解合并为原问题的解

已学过的分治算法：二分搜索、归并排序。

---

## 三、选择问题（第 k 小元素）

### 3.1 问题

给定无序数组 $A[1..n]$，找出其中第 $k$ 小的元素。

- $k = 1$：最小值（$O(n)$ 一次遍历）
- $k = n/2$：中位数
- 排序后取第 $k$ 个：$O(n \log n)$

能否在 $O(n)$ 时间内解决？

### 3.2 划分（Partition）

核心子程序：选取一个**主元（pivot）**，将数组划分为两部分——左侧元素 $\leq$ pivot，右侧元素 $\geq$ pivot。

```
Partition(A, low, high):
    pivot ← A[low]          // 选第一个元素为主元
    i ← low
    for j ← low+1 to high:
        if A[j] < pivot:
            i ← i + 1
            swap(A[i], A[j])
    swap(A[low], A[i])      // 主元归位
    return i                // 返回主元最终位置
```

执行后：$A[low..i-1] \leq A[i] \leq A[i+1..high]$

### 3.3 快速选择算法

```
QuickSelect(A, low, high, k):
    if low = high:
        return A[low]
    pivot_pos ← Partition(A, low, high)
    left_len ← pivot_pos - low + 1
    if k = left_len:
        return A[pivot_pos]
    elif k < left_len:
        return QuickSelect(A, low, pivot_pos-1, k)
    else:
        return QuickSelect(A, pivot_pos+1, high, k - left_len)
```

### 3.4 复杂度分析

- **最坏情况**：每次 pivot 都是最小/最大元素，$T(n) = T(n-1) + O(n) = O(n^2)$
- **平均情况**：每次约减半，$T(n) = T(n/2) + O(n) = O(n)$
- 随机选 pivot 可使最坏概率极低

---

## 四、双指针技巧：有序数组的两数之和

### 4.1 问题

给定升序数组 $A[1..n]$，判断是否存在两个不同下标 $i, j$ 使得 $A[i] + A[j] = target$。

### 4.2 双指针算法

```
i ← 1, j ← n
while i < j:
    sum ← A[i] + A[j]
    if sum = target: return (i, j)
    elif sum < target: i ← i + 1
    else: j ← j - 1
return "不存在"
```

**时间复杂度**：$O(n)$，仅遍历数组一遍。

**正确性归纳**：每次移动指针都排除了不可能包含解的一侧，搜索空间不断缩小。

---

## 五、快速参考

| 算法 | 时间（最坏） | 时间（平均） | 空间 |
|------|-------------|-------------|------|
| 快速幂 | $\Theta(\log n)$ | $\Theta(\log n)$ | $O(1)$ |
| 快速选择 | $O(n^2)$ | $O(n)$ | $O(1)$ |
| 双指针 2-Sum | $O(n)$ | $O(n)$ | $O(1)$ |

| 分治三步 | 说明 |
|----------|------|
| 分解 | 拆成规模更小的子问题 |
| 治理 | 递归求解子问题 |
| 合并 | 将子问题解合并为最终解 |
