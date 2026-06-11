#include <bits/stdc++.h>
using namespace std;


pair<int, int> find_mul(vector<int>& a, int n, int c) {
    int count = 0;
    for (int j = 1; j <= n; ++j) {
        if (a[j] == c) count++;
    }
    if (count > n / 2) return {c, 1};
    else return {0, 0};
}

int candidata(vector<int>& a, int n, int m) {
    int j = m;
    int c = a[m];
    int count = 1;
    while (j < n && count > 0) {
        j = j + 1;
        if (a[j] == c) count++;
        else count--;
    }
    if (j == n) return c;
    else return candidata(a, n, j + 1);
}

int candidata2(vector<int>& a, int n, int m) {
    while (m <= n) {
        int count = 1;
        int j = m;
        int c = a[m];
        while (j < n && count > 0) {
            j = j + 1;
            if (a[j] == c) count++;
            else count--;
        }
        if (j == n) return c;
        else m = j + 1;
    }
    return 0;
}

int main() {
    vector<int> a = {0, 2, 1, 1, 3, 3, 1, 1, 7, 1};
    int n = a.size() - 1;
    auto [x, flag] = find_mul(a, n, candidata2(a, n, 1));
    if (flag) cout << x << endl;
    else cout << "not found" << endl;
}