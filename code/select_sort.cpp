#include <bits/stdc++.h>
using namespace std;

int SELECT(vector<int>& a, int low, int high) {
    int idx = low;
    int mn = a[low];
    for (int j = low + 1; j <= high; ++j) {
        if (a[j] < mn) {
            mn = a[j];
            idx = j;
        }
    }
    return idx;
}

void select_sort(vector<int>& a, int n) {
    int i = 1;
    while (i < n) {
        int j = SELECT(a, i, n);
        swap(a[i], a[j]);
        i = i + 1;        
    }
}

int main() {
    vector<int> a = {0, 2, 1, 4, 3, 5};
    select_sort(a, 5);
    for (int i = 1; i <= 5; ++i) {
        cout << a[i] << ' ';
    }
    cout << endl;
}