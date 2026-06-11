#include <bits/stdc++.h>
using namespace std;

void INSERT(vector<int>& a, int low, int i) {
    int x = a[i];
    int j = i - 1;
    while (j >= low && a[j] > x) {
        a[j + 1] = a[j];
        j = j - 1;
    }
    a[j + 1] = x;
}

void insert_sort(vector<int>& a, int low, int high) {
    int j = low + 1;
    while (j <= high) {
        INSERT(a, low, j);
        j = j + 1;
    }
}

pair<int, int> PARTITION(vector<int>& a, int low, int high, int mm) {
    int l = low;
    int r = high;
    int i = low;
    while (i <= r) {
        if (a[i] < mm) {
            swap(a[i], a[l]);
            l++;
            i++;
        } else if (a[i] > mm) {
            swap(a[i], a[r]);
            r--;
        } else {
            i++;
        }
    }
    return {l - 1, r + 1};
}

int select(vector<int>& a, int low, int high, int k) {
    int p = high - low + 1;
    if (p < 44) {
        insert_sort(a, low, high);
        return a[low + k - 1];
    }
    int q = p / 5;
    for (int j = 1; j <= q; ++j) {
        int s = low + (j - 1) * 5;
        int e = min(s + 4, high);
        insert_sort(a, s, e);
        swap(a[low + j - 1], a[(s + e) / 2]);
    }
    int mm = select(a, low, low + q - 1, (q + 1) / 2);
    auto [a1e, a3s] = PARTITION(a, low, high, mm);
    int A1 = a1e - low + 1;
    int A2 = a3s - 1 - (a1e + 1) + 1;
    if (A1 >= k) {
        return select(a, low, a1e, k);
    } else if (A1 + A2 >= k) {
        return mm;
    } else {
        return select(a, a3s, high, k - A1 - A2);
    }
}

int check(vector<int> a, int k) {
    int n = a.size() - 1;
    int ans = select(a, 1, n, k);
    sort(a.begin() + 1, a.end());
    return ans == a[k];
}

int main() {
    int pass = 0, fail = 0;

    // 手动 case
    auto test_one = [&](vector<int> a, int k, int expected) {
        int got = select(a, 1, a.size() - 1, k);
        if (got == expected) pass++;
        else { fail++; cout << "FAIL: k=" << k << " expected=" << expected << " got=" << got << endl; }
    };

    test_one({0,8,33,17,51,57,49,35,11,25,37,14,3,2,13,52,12,6,29,32,54,5,16,22,23,7}, 13, 22);

    // 小数组（走 insert_sort）
    test_one({0,5,2,9,1,5,6}, 3, 5);
    test_one({0,1,2,3,4,5}, 1, 1);
    test_one({0,9,7,5,3,1}, 5, 9);
    test_one({0,4,2,4,2,4}, 1, 2);
    test_one({0,42}, 1, 42);
    test_one({0,7,7,7,7}, 2, 7);
    test_one({0,3,1}, 1, 1);
    test_one({0,3,1}, 2, 3);

    // 大数组（走完整 BFPRT），随机测试
    srand(42);
    for (int t = 0; t < 20; t++) {
        int n = 50 + rand() % 100;  // 50~149 确保超过阈值 44
        vector<int> a(n + 1);
        a[0] = 0;
        for (int i = 1; i <= n; i++) a[i] = rand() % 1000;
        for (int k = 1; k <= n; k += n / 5 + 1) {  // 测 5 个 k
            if (check(a, k)) pass++;
            else { fail++; cout << "FAIL: n=" << n << " k=" << k << endl; }
        }
    }

    cout << pass << " passed, " << fail << " failed" << endl;
}