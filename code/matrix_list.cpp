#include <bits/stdc++.h>
using namespace std;

int main () {
    vector<pair<int, int>> M ={
        {0, 0}, {5, 10}, {10, 4}, {4, 6},
        {6, 10}, {10, 2}
    };
    int n = M.size() - 1;
    vector<int> r(n + 2);
    r[n + 1] = M[n].second;
    for (int i = 1; i <= n; ++i) {
        r[i] = M[i].first;
    }
    auto dp = vector(n + 1, vector<int>(n + 1, 1 << 30));
    for (int i = 1; i <= n; ++i) {
        dp[i][i] = 0;
    }
    for (int l = 2; l <= n; ++l) {
        for (int i = 1; i <= n; ++i) {
            int j = i + l - 1;
            if (j > n) break;
            for (int k = i + 1; k <= j; ++k) {
                dp[i][j] = min(
                    dp[i][j],
                    dp[i][k - 1] + dp[k][j] + r[i] * r[k] * r[j + 1]
                );
            }
        }
    }
    cout << dp[1][n] << endl;
}