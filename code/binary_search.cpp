#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int>& a, int x, int low, int high) {
    if (low > high) return 0;
    else {
        int mid = (low + high) / 2;
        if (x == a[mid]) {
            return mid;
        } else if (x < a[mid]) {
            return binary_search(a, x, low, mid - 1);
        } else {
            return binary_search(a, x, mid + 1, high);
        }
    }
}

int main() {
    vector<int> a = {0, 1, 2, 3, 3, 4, 4, 6, 10};
    int n = a.size() - 1;
    cout << binary_search(a, 6, 1, n) << endl;
}