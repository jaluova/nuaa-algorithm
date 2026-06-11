#include <bits/stdc++.h>
using namespace std;

int search_max(vector<int>& a, int low, int high) {
    if (low == high) return a[low];
    else {
        int mid = (low + high + 1) / 2;
        if (a[mid] > a[low]) {
            return search_max(a, mid, high);
        } else {
            return search_max(a, low, mid - 1);
        }
    }
}

int main() {
    vector<int> a = {0, 4, 4, 6, 10, 1, 2, 3, 3};
    int n = a.size() - 1;
    cout << search_max(a, 1, n) << endl;
}