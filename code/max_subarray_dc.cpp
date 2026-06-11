#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct Node {
    int leftMax;   // 从区间左端开始的最大连续子数组和
    int rightMax;  // 到区间右端结束的最大连续子数组和
    int totalMax;  // 区间内任意位置的最大子数组和
    int sum;       // 区间总和
};

Node merge(Node L, Node R) {
    Node res;
    res.sum = L.sum + R.sum;
    res.leftMax = max(L.leftMax, L.sum + R.leftMax);
    res.rightMax = max(R.rightMax, R.sum + L.rightMax);
    res.totalMax = max({L.totalMax, R.totalMax, L.rightMax + R.leftMax});
    return res;
}

Node solve(vector<int>& A, int l, int r) {
    if (l == r) {
        int v = A[l];
        return {v, v, v, v};
    }
    int mid = (l + r) / 2;
    Node left = solve(A, l, mid);
    Node right = solve(A, mid + 1, r);
    return merge(left, right);
}

void test(vector<int> A, int expected) {
    Node ans = solve(A, 0, A.size() - 1);
    cout << "max = " << ans.totalMax
         << (ans.totalMax == expected ? " [OK]" : " [FAIL, expected " + to_string(expected) + "]")
         << endl;
}

int main() {
    // 例题
    test({-2, 1, -3, 4, -1, 2, 1, -5, 4}, 6);

    // 全正数
    test({1, 2, 3, 4, 5}, 15);

    // 全负数
    test({-5, -2, -9, -1}, -1);

    // 单元素
    test({42}, 42);

    // 单元素负数
    test({-7}, -7);

    // 最大在左侧
    test({10, -1, -1, -1, 1, 1}, 10);

    // 最大在右侧
    test({-1, -1, 1, 1, 10}, 12);  // 1+1+10 = 12

    // 最大跨越中点
    test({-2, 5, -1, 5, -2}, 9);  // 5 + (-1) + 5 = 9

    // 连续正负交替
    test({2, -1, 2, -1, 2}, 4);   // 2-1+2-1+2 = 4

    // 有0
    test({0, -1, 3, -2, 4}, 5);   // 3 + (-2) + 4 = 5

    return 0;
}
