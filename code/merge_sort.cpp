#include <bits/stdc++.h>
using namespace std;

void MERGE(vector<int>& a, int low, int mid, int high) {
    vector<int> L(a.begin() + low, a.begin() + mid + 1);
    vector<int> R(a.begin() + mid + 1, a.begin() + high + 1);

    int i = 0, j = 0;
    int n = mid - low + 1;
    int m = high - mid;
    int k = low;
    while (i < n && j < m) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
            k++;
        } else {
            a[k] = R[j];
            j++;
            k++;
        }
    }
    while (i < n) {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < m) {
        a[k] = R[j];
        j++;
        k++;
    }
}


void merge_sort(vector<int>& a, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        merge_sort(a, low, mid);
        merge_sort(a, mid + 1, high);
        MERGE(a, low, mid, high);
    }
}

void test(vector<int> a) {          // 传值，保留原数组用于每组独立测试
    int n = a.size() - 1;          // a[0] 是占位，有效数据 1..n
    merge_sort(a, 1, n);
    for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
    cout << endl;
}

int main() {
    // 1. 随机
    test({0, 5, 2, 9, 1, 5, 6});
    // 2. 已有序
    test({0, 1, 2, 3, 4, 5});
    // 3. 逆序
    test({0, 9, 7, 5, 3, 1});
    // 4. 有重复
    test({0, 4, 2, 4, 2, 4});
    // 5. 单元素
    test({0, 42});
    // 6. 全部相同
    test({0, 7, 7, 7, 7});
    // 7. 两个元素
    test({0, 3, 1});
    // 8. 长数组
    test({0, 11, 4, 14, 2, 9, 6, 12, 8, 3, 15, 7, 1, 13, 5, 10});
}