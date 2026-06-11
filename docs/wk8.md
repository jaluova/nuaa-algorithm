某学生甲平时不认真学习，打算在期末考试前进行突击复习。假设学生甲共有 $n$ 门课要考试，每门课的学分分别是 $X_1,X_2,\dots,X_n$；如果想各门课程的考试及格，需要的复习时间分别是 $T_1,T_2,\dots,T_n$ 小时，即学生甲如果想第 $i$ 门课程考试及格，需要花费 $T_i$ 个小时复习该门课程。然而，学生甲共计只有 $C$ 小时的时间用来复习所有的课程。请使用动态规划的思想，设计一个 $O(n \times C)$ 的算法，求学生甲所能考及格的课程学分之和的最大值。（提示：类似背包问题）
要求： 
1. 给出上述问题最优解的表示方法和递推关系式； 
2. 给出算法的伪代码，并添加必要的注释； 
3. 分析所设计算法的时间复杂度。


设 $T_i$ 看成“花费”、$X_i$ 看成“价值”，这道题就是一个标准的 $0/1$ 背包问题：每门课只能选或不选一次，在总复习时间不超过 $C$ 的前提下，使及格课程的总学分最大。

**1. 状态表示与递推关系**
令 $dp[i][j]$ 表示：

在只考虑前 $i$ 门课程、总复习时间不超过 $j$ 小时时，所能获得的最大及格学分和。

则最终答案为 $dp[n][C]$。

初始条件为：
- $dp[0][j] = 0$，$0 <= j <= C$
- $dp[i][0] = 0$，$0 <= i <= n$

含义是：没有课程可选，或没有复习时间时，最大可得学分都是 $0$。

对第 $i$ 门课，有两种选择：

1. 不复习第 $i$ 门课  
   则 $dp[i][j] = dp[i-1][j]$

2. 复习第 $i$ 门课  
   前提是 $j >= T_i$，则  
   $dp[i][j] = dp[i-1][j-T_i] + X_i$

因此递推关系式为：

- 当 $j < T_i$ 时：
  $dp[i][j] = dp[i-1][j]$

- 当 $j >= T_i$ 时：
  $dp[i][j] = max(dp[i-1][j], dp[i-1][j-T_i] + X_i)$

**2. 伪代码**
$$
\begin{array}{l}
\textbf{Algorithm } \mathrm{MaxCredits}(X[1..n], T[1..n], C) \\[2mm]
\quad \text{// } dp[i][j]\text{ 表示前 } i \text{ 门课在总时间不超过 } j \text{ 时的最大学分和} \\
\quad \text{create array } dp[0..n][0..C] \\[2mm]

\quad \text{// 初始化：没有课程可选时，最大学分为 } 0 \\
\quad \mathbf{for}\ j = 0\ \mathbf{to}\ C\ \mathbf{do} \\
\qquad dp[0][j] \leftarrow 0 \\[2mm]

\quad \text{// 依次处理每一门课程} \\
\quad \mathbf{for}\ i = 1\ \mathbf{to}\ n\ \mathbf{do} \\
\qquad dp[i][0] \leftarrow 0 \qquad \text{// 时间为 } 0 \text{ 时，不可能复习任何课程} \\
\qquad \mathbf{for}\ j = 1\ \mathbf{to}\ C\ \mathbf{do} \\
\qquad\qquad dp[i][j] \leftarrow dp[i-1][j] \\
\qquad\qquad \mathbf{if}\ j \ge T[i]\ \mathbf{then} \\
\qquad\qquad\qquad dp[i][j] \leftarrow \max(dp[i][j],\ dp[i-1][j-T[i]] + X[i]) \\[2mm]

\quad \mathbf{return}\ dp[n][C]
\end{array}
$$

如果想说明得更完整，也可以补一句：  
$dp[n][C]$ 就是学生甲在 $C$ 小时内最多能获得的及格课程总学分。

**3. 时间复杂度分析**
算法中有两层循环：

- 外层循环遍历 $n$ 门课程
- 内层循环遍历 $0$ 到 $C$ 的时间容量

每次状态转移只需常数时间，所以总时间复杂度为：
$$
O(n × C)
$$
如果采用上面的二维数组，空间复杂度是：
$$
O(n × C)
$$
补充一句：若只要求最大值、不要求恢复具体选了哪些课程，还可以把空间优化到 $O(C)$。
