#include <bits/stdc++.h>
using namespace std;

void INSERT(vector<int>& a, int i) {
    int x = a[i];
    int j = i - 1;
    while (j >= 1 && a[j] > x) {
        a[j + 1] = a[j];
        j = j - 1;
    }
    a[j + 1] = x;
}

void insert_sort(vector<int>& a, int n) {
    int j = 2;
    while (j <= n) {
        INSERT(a, j);
        j = j + 1;
    }
}

void test(vector<int> a) {
    int n = a.size() - 1;
    insert_sort(a, n);
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