#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {0, 2, 3, 4, 5};
    int n = a.size();
    int lo = 1, hi = n - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (a[mid] > mid) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo << endl;
}
