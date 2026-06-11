#include <bits/stdc++.h>
using namespace std;

int main() {
    string a = "aabbcc";
    string b = "aacc";
    int n = a.size();
    int m = b.size();
    vector<vector<int>> L(n + 1, vector<int>(m + 1));
    for (int i = 0; i <= n; ++i) {
        L[i][0] = 0;
    }
    for (int i = 0; i <= m; ++i) {
        L[0][i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i - 1] == b[j - 1]) L[i][j] = L[i][j - 1] + 1;
            else L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    cout << L[n][m] << endl;
    string ans;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            ans.push_back(a[i - 1]);
            i--, j--;
        } else if (L[i - 1][j] > L[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}