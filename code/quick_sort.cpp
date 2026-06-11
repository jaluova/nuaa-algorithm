#include <bits/stdc++.h>
using namespace std;

int SPLIT(vector<int>& a, int low, int high) {
    int x = a[low];
    int i = low + 1;
    int j = high;
    while (i <= j) {
        if (a[i] > x) {
            swap(a[i], a[j]);
            j--;
        } else {
            i++;
        }
    }
    swap(a[low], a[i - 1]);
    return i - 1;
}

void quick_sort(vector<int>& a, int low, int high) {
    if (low < high) {
        int m = SPLIT(a, low, high);
        quick_sort(a, low, m - 1);
        quick_sort(a, m + 1, high);
    }
}

void test(vector<int> a) {
    int n = a.size() - 1;
    quick_sort(a, 1, n);
    for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
    cout << endl;
}

int main() {
    cout << "随机:     "; test({0, 5, 2, 9, 1, 5, 6});
    cout << "已有序:   "; test({0, 1, 2, 3, 4, 5});
    cout << "逆序:     "; test({0, 9, 7, 5, 3, 1});
    cout << "有重复:   "; test({0, 4, 2, 4, 2, 4});
    cout << "单元素:   "; test({0, 42});
    cout << "全相同:   "; test({0, 7, 7, 7, 7});
    cout << "两个元素: "; test({0, 3, 1});
    cout << "长数组:   "; test({0, 11, 4, 14, 2, 9, 6, 12, 8, 3, 15, 7, 1, 13, 5, 10});
}