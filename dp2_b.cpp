#include <vector>
#include <iostream>

using namespace std;

int main() {
    int n, w;
    cin >> n >> w;

    vector<vector<bool>> dp(n + 1, vector<bool> (w + 1));

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        int cur_wight;
        cin >> cur_wight;
        for (int j = 1; j <= w; j++) {
            dp[i][j] = (j == cur_wight) || (dp[i - 1][j]) || (j > cur_wight && dp[i - 1][j - cur_wight]);
            ans = dp[i][j] ? j : ans;
        }
    }
    cout << ans;
    return 0;
}
