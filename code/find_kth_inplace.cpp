#include <bits/stdc++.h>
using namespace std;

void insert_sort(vector<int>& a, int low, int high) {
    for (int i = low + 1; i <= high; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= low && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

// 三路划分：< mm | == mm | > mm，返回 {a1_end, a3_start}
pair<int, int> partition(vector<int>& A, int low, int high, int mm) {
    int i = low, l = low, r = high;
    while (i <= r) {
        if (A[i] < mm) {
            swap(A[i], A[l]);
            i++; l++;
        } else if (A[i] > mm) {
            swap(A[i], A[r]);
            r--;
        } else {
            i++;
        }
    }
    return {l - 1, r + 1};
}

int select(vector<int>& A, int low, int high, int k) {
    int p = high - low + 1;
    if (p < 44) {
        insert_sort(A, low, high);
        return A[low + k - 1];
    }

    int q = p / 5;

    // 原地：各组排序后，把中位数换到 A[low .. low+q-1]
    for (int j = 1; j <= q; j++) {
        int s = low + (j - 1) * 5;
        int e = min(s + 4, high);
        insert_sort(A, s, e);
        swap(A[low + j - 1], A[(s + e) / 2]);
    }

    int mm = select(A, low, low + q - 1, (q + 1) / 2);

    auto [a1_end, a3_start] = partition(A, low, high, mm);

    int sz1 = a1_end - low + 1;
    int sz2 = a3_start - a1_end - 1;

    if (sz1 >= k)
        return select(A, low, a1_end, k);
    else if (sz1 + sz2 >= k)
        return mm;
    else
        return select(A, a3_start, high, k - sz1 - sz2);
}

int main() {
    vector<int> a = {0,8,33,17,51,57,49,35,11,25,37,14,3,2,13,52,12,6,29,32,54,5,16,22,23,7};
    int x = select(a, 1, a.size() - 1, 13);
    cout << x << endl;  // 22
}
