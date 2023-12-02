#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> dp(n + 1);

    for (int i = 1; i <= n; i++) {
        int price;
        cin >> price;
        if (i > 1) {
            dp[i] = min(dp[i - 1] + price, dp[i - 2] + price);
        } else {
            dp[i] = dp[i - 1] + price;
        }
    }

    cout << dp[n];

    return 0;
}
