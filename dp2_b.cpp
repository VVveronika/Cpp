#include <vector>
#include <iostream>

using namespace std;

int main() {
    int n, w;
    cin >> n >> w;

    vector<bool> dp(w + 1);

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        int cur_wight;
        cin >> cur_wight;
        for (int j = w; j > 0; j--) {
            dp[j] = dp[j] || j == cur_wight || (j > cur_wight && dp[j - cur_wight]);
            ans = dp[j] ? max(j, ans) : ans;
        }
    }
    cout << ans;
    return 0;
}
