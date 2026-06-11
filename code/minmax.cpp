#include <bits/stdc++.h>
using namespace std;

pair<int, int> minmax(vector<int>& a, int low, int high) {
    if (low == high) return {a[low], a[low]};
    int mid = (low + high) / 2;
    auto [x1, y1] = minmax(a, low, mid);
    auto [x2, y2] = minmax(a, mid + 1, high);
    return {min(x1, x2), max(y1, y2)};
}

int main() {
    vector<int> a = {0, 1, 1, 4, 5, 1, 4, 6, -1};
    int n = a.size() - 1;
    auto [x, y] = minmax(a, 1, n);
    cout << x << " " << y << endl;
}