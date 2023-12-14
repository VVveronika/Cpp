#include <vector>
#include <iostream>

using namespace std;

int main() {
    int n, w;
    cin >> n >> w;

    vector<vector<bool>> dp(n + 1, vector<bool> (w + 1));
    string ans = "no";

    for (int i = 1; i <= n; i++) {
        int w_obj;
        cin >> w_obj;
        for (int j = 1; j <= w; j++) {
            dp[i][j] = dp[i - 1][j] || (j >= w_obj && dp[i - 1][j - w_obj]);
        }
        dp[i][w_obj] = true;

        if (dp[i][w]) {
            ans = "yes";
            break;
        }
    }
    cout << ans;
    return 0;
}
