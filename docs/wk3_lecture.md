# 算法第3周讲义：渐进复杂度分析 + 习题全解

---

## 一、核心概念：三种渐进符号

### 1.1 直觉理解

| 符号 | 含义 | 类比 |
|------|------|------|
| $f = O(g)$ | $f$ 增长**不超过** $g$ | $f \leq g$（忽略常数） |
| $f = \Omega(g)$ | $f$ 增长**不低于** $g$ | $f \geq g$（忽略常数） |
| $f = \Theta(g)$ | $f$ 和 $g$ 增长**同量级** | $f \approx g$（忽略常数） |

### 1.2 正式定义

$$f = O(g) \iff \exists\, c > 0,\ n_0,\ \text{使得对所有 } n \geq n_0：f(n) \leq c \cdot g(n)$$

$$f = \Omega(g) \iff \exists\, c > 0,\ n_0,\ \text{使得对所有 } n \geq n_0：f(n) \geq c \cdot g(n)$$

$$f = \Theta(g) \iff f = O(g) \text{ 且 } f = \Omega(g)$$

### 1.3 极限判断法（最实用的工具）

计算 $\displaystyle L = \lim_{n \to \infty} \frac{f(n)}{g(n)}$，然后：

$$L = \begin{cases} 0 & \Rightarrow f = O(g),\quad f \neq \Omega(g),\quad f \neq \Theta(g) \\ 0 < L < \infty & \Rightarrow f = O(g),\quad f = \Omega(g),\quad f = \Theta(g) \\ \infty & \Rightarrow f \neq O(g),\quad f = \Omega(g),\quad f \neq \Theta(g) \end{cases}$$

**总结规律**：
- 极限 = 0：$f$ 比 $g$ "小"，$f = O(g)$ 为真，$\Omega$ 和 $\Theta$ 为假
- 极限 = 常数：两者同阶，三个都为真
- 极限 = ∞：$f$ 比 $g$ "大"，$\Omega$ 为真，$O$ 和 $\Theta$ 为假

---

## 二、增长速度排行榜（从慢到快）

$$1 \ll \log\log n \ll \log n \ll (\log n)^2 \ll (\log n)^{100} \ll n^{0.01} \ll \sqrt{n} \ll n \ll n\log n \ll n^2 \ll n^3 \ll 2^n \ll 5^n \ll 100^n \ll n! \ll n^n$$

**关键结论**：
- 任何多项式对数 $(\log n)^k$ 都比任何多项式 $n^\epsilon$（$\epsilon > 0$）增长慢
- 任何指数 $a^n$（$a > 1$）都比任何多项式 $n^k$ 增长快
- $n!$ 比任何固定底数的指数都增长快（Stirling 近似：$n! \approx \sqrt{2\pi n}\left(\frac{n}{e}\right)^n$）

---

## 三、Theta 化简的五条规则

**规则1：去掉常数系数**
$$\Theta(c \cdot f(n)) = \Theta(f(n))$$
例：$\Theta(100n^2) = \Theta(n^2)$

**规则2：只保留主项（加法取最大）**
$$\Theta(f(n) + g(n)) = \Theta(\max(f(n), g(n)))$$
例：$\Theta(n^3 + n^2 + 1) = \Theta(n^3)$

**规则3：$\log n^k = k\log n$，结果仍是 $\Theta(\log n)$**
$$\log n^k = k \log n \Rightarrow \Theta(\log n^k) = \Theta(\log n)$$

**规则4：注意指数写法**
- $(\sqrt{n})^3 = n^{3/2} = n^{1.5}$
- $(\log n)^2$ 是对数的平方，远小于 $n^{0.01}$
- $\log^{100} n$ 指 $(\log n)^{100}$，仍然比任何 $n^\epsilon$ 小

**规则5：分式化简**
$$\frac{n^3 + n}{n + 5} \approx \frac{n^3}{n} = n^2 \quad (\text{做多项式除法})$$

---

## 四、习题全解

### 第1题：真值表

**判断方法**：对每行计算 $\lim \frac{f(n)}{g(n)}$。

---

**行1**：$f = 2n^3 + 3n$，$g = 100n^2 + 2n + 100$

$$\lim \frac{2n^3 + 3n}{100n^2 + 2n + 100} = \lim \frac{2n^3}{100n^2} = \lim \frac{n}{50} = \infty$$

极限为 $\infty$，$f$ 增长更快。

| $f=O(g)$ | $f=\Omega(g)$ | $f=\Theta(g)$ |
|----------|---------------|---------------|
| **false** | **true** | **false** |

---

**行2**：$f = 50n + \log n$，$g = 10n + \log\log n$

主项都是 $n$，$f \sim 50n$，$g \sim 10n$：

$$\lim \frac{50n + \log n}{10n + \log\log n} = \lim \frac{50n}{10n} = 5 \quad (\text{有限非零常数})$$

| $f=O(g)$ | $f=\Omega(g)$ | $f=\Theta(g)$ |
|----------|---------------|---------------|
| **true** | **true** | **true** |

---

**行3**：$f = 50n\log n$，$g = 10n\log\log n$

$$\lim \frac{50n\log n}{10n\log\log n} = 5 \cdot \lim \frac{\log n}{\log\log n}$$

令 $m = \log n$，则 $\log\log n = \log m$，极限变为 $\displaystyle\lim_{m\to\infty}\frac{m}{\log m} = \infty$。

$f$ 增长更快。

| $f=O(g)$ | $f=\Omega(g)$ | $f=\Theta(g)$ |
|----------|---------------|---------------|
| **false** | **true** | **false** |

---

**行4**：$f = \log n$，$g = \log^2 n = (\log n)^2$

$$\lim \frac{\log n}{(\log n)^2} = \lim \frac{1}{\log n} = 0$$

$f$ 比 $g$ 增长慢。

| $f=O(g)$ | $f=\Omega(g)$ | $f=\Theta(g)$ |
|----------|---------------|---------------|
| **true** | **false** | **false** |

---

**行5**：$f = n!$，$g = 5^n$

由增长排行榜，$n! \gg 5^n$（对足够大的 $n$），可用 Stirling 近似或直接观察：
当 $n > 5$，$n! = n \cdot (n-1) \cdots 1$，而 $5^n = 5 \cdot 5 \cdots 5$（$n$ 个 5）。
$n$ 足够大后每个因子 $k > 5$ 都使 $n!$ 超越 $5^n$ 的对应因子，故 $n!/5^n \to \infty$。

| $f=O(g)$ | $f=\Omega(g)$ | $f=\Theta(g)$ |
|----------|---------------|---------------|
| **false** | **true** | **false** |

---

### 第2题：用 Theta 表示（基础版）

**(a) $2n + 3\log^{100} n$**

比较 $n$ 和 $(\log n)^{100}$：由规则，$(\log n)^{100} = o(n)$（对数的任何幂都比 $n$ 小）。

主项是 $n$：

$$\boxed{\Theta(n)}$$

**(b) $7n^3 + 1000n\log n + 3n$**

三项中 $n^3$ 最大（$n^3 \gg n\log n \gg n$）：

$$\boxed{\Theta(n^3)}$$

**(c) $3n^{1.5} + (\sqrt{n})^3\log n$**

注意 $(\sqrt{n})^3 = (n^{1/2})^3 = n^{3/2} = n^{1.5}$。

所以两项变为：
$$3n^{1.5} + n^{1.5}\log n$$

提取公因子：$n^{1.5}(3 + \log n)$

$\log n$ 增长比常数 3 快，所以 $(3 + \log n) = \Theta(\log n)$：

$$\boxed{\Theta(n^{1.5}\log n)}$$

**(d) $2^n + 100^n + n!$**

比较三者增长速度：$n! \gg 100^n \gg 2^n$

主项是 $n!$：

$$\boxed{\Theta(n!)}$$

---

### 第3题：用 Theta 表示（进阶版）

**(a) $18n^3 + \log n^8$**

注意 $\log n^8 = 8\log n$（对数的幂律），这是 $\Theta(\log n)$。

比较 $n^3$ 和 $\log n$：$n^3 \gg \log n$，主项是 $n^3$：

$$\boxed{\Theta(n^3)}$$

**(b) $\dfrac{n^3 + n}{n + 5}$**

做多项式长除法：

$$\frac{n^3 + n}{n + 5} = n^2 - 5n + 26 - \frac{130}{n+5}$$

（验证：$(n^2 - 5n + 26)(n+5) = n^3 + 5n^2 - 5n^2 - 25n + 26n + 130 = n^3 + n + 130$，差一点；精确展开略）

**更简单的方法**：当 $n$ 很大，$n + 5 \approx n$，所以：

$$\frac{n^3 + n}{n + 5} \approx \frac{n^3}{n} = n^2$$

严格地：$\dfrac{n^3}{2n} \leq \dfrac{n^3+n}{n+5} \leq \dfrac{2n^3}{n}$，夹逼得：

$$\boxed{\Theta(n^2)}$$

**(c) $\log^2 n + \sqrt{n} + \log\log n$**

三项大小比较：
- $\sqrt{n} = n^{0.5}$（多项式）
- $\log^2 n = (\log n)^2$（对数的幂，小于任何 $n^\epsilon$）
- $\log\log n$（更小）

所以 $\sqrt{n} \gg \log^2 n \gg \log\log n$，主项是 $\sqrt{n}$：

$$\boxed{\Theta(\sqrt{n})}$$

**(d) $\dfrac{n!}{2^n} + n^{n/2}$**

分析两项：

**第一项** $n!/2^n$：$n! \gg 2^n$，故 $n!/2^n \to \infty$。实际上 $n!/2^n = \Theta(n!/2^n)$ 本身就很大。

**第二项** $n^{n/2} = (n^n)^{1/2} = \sqrt{n^n}$。

比较 $n!$ 和 $n^{n/2}$：

用 Stirling：$n! \approx \sqrt{2\pi n}\left(\frac{n}{e}\right)^n$，而 $n^{n/2}$。

$$\frac{n!}{n^{n/2}} \approx \frac{\left(\frac{n}{e}\right)^n}{n^{n/2}} = \frac{n^n}{e^n \cdot n^{n/2}} = \frac{n^{n/2}}{e^n} = \left(\frac{\sqrt{n}}{e}\right)^n \to \infty$$

所以 $n! \gg n^{n/2}$，从而 $n!/2^n \gg n^{n/2}$（因为 $n!/2^n$ 比 $n!$ 只小一个指数倍，仍远大于 $n^{n/2}$）。

主项是 $n!/2^n$：

$$\boxed{\Theta\!\left(\frac{n!}{2^n}\right)}$$

---

### 第4题：多项式求值算法

设多项式 $P(x) = a_n x^n + a_{n-1}x^{n-1} + \cdots + a_1 x + a_0$

---

**(a) 时间复杂度为 $\Omega(n^2)$ 的算法（朴素法）**

**思路**：逐项计算每个 $a_i x^i$，计算 $x^i$ 时用循环连乘 $i$ 次。

**伪代码**：
```
NaivePolyEval(a[0..n], x):
    result = 0
    for i = 0 to n:
        term = a[i]
        for j = 1 to i:          // 计算 x^i，需要 i 次乘法
            term = term * x
        result = result + term
    return result
```

**复杂度分析**：

内层循环第 $i$ 次执行 $i$ 次乘法，总乘法次数为：
$$\sum_{i=0}^{n} i = \frac{n(n+1)}{2} = \Theta(n^2)$$

因此时间复杂度为 $\Theta(n^2)$，满足 $\Omega(n^2)$。

---

**(b) 时间复杂度为 $O(n)$ 的算法（Horner 法）**

**核心思想**（秦九韶算法）：将多项式改写为嵌套形式，避免重复计算 $x$ 的幂次：

$$a_n x^n + a_{n-1}x^{n-1} + \cdots + a_1 x + a_0 = (\cdots((a_n x + a_{n-1})x + a_{n-2})x + \cdots)x + a_0$$

**示例**（$n=3$）：
$$a_3 x^3 + a_2 x^2 + a_1 x + a_0 = ((a_3 x + a_2)x + a_1)x + a_0$$

**伪代码**：
```
HornerPolyEval(a[0..n], x):
    result = a[n]              // 从最高次系数开始
    for i = n-1 downto 0:
        result = result * x + a[i]
    return result
```

**复杂度分析**：

循环执行 $n$ 次，每次 1 次乘法 + 1 次加法，总操作数为 $2n = \Theta(n)$。

满足 $O(n)$（实际上是 $\Theta(n)$，这是已知的最优算法）。

**手动验证**（$n=2$，$P(x) = 3x^2 + 2x + 1$，$x = 4$）：

- 真实值：$3(16) + 2(4) + 1 = 48 + 8 + 1 = 57$
- Horner：$\text{result} = 3$，$\to 3 \times 4 + 2 = 14$，$\to 14 \times 4 + 1 = 57$ ✓

---

## 五、快速参考卡片

| 情形 | 结论 |
|------|------|
| $\lim f/g = 0$ | $f = O(g)$，其余假 |
| $\lim f/g = c > 0$ | $f = \Theta(g)$，三个都真 |
| $\lim f/g = \infty$ | $f = \Omega(g)$，其余假 |
| $f + g$，取主项 | $\Theta(\max(f, g))$ |
| $\log n^k$ | $= \Theta(\log n)$ |
| $(\log n)^k$ vs $n^\epsilon$ | $(\log n)^k$ 更小 |
| 多项式 $n^a$ vs 指数 $b^n$，$b > 1$ | $b^n$ 更大 |
| $n!$ vs $b^n$，$b > 1$ | $n!$ 更大 |
