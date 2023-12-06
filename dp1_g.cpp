#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dp(n + 1, vector<int> (m + 1));
    dp[1][1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            dp[i][j] = dp[i - 2][j - 1] + dp[i - 1][j - 2];
        }
    }

    cout << dp[n][m];

    return 0;
}
