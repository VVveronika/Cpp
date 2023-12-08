#include <vector>
#include <iostream>

using namespace std;

int main() {
    const int type = 3;
    int n;
    cin >> n;

    vector<vector<int>> dp(n, vector<int> (type));
    dp[0][0] = 1;
    dp[0][1] = 1;
    dp[0][2] = 1;

    int summ = 3;

    for (int i = 1; i < n; i++) {
        int dp_0 = dp[i - 1][0];
        int dp_1 = dp[i - 1][1];
        int dp_2 = dp[i - 1][1];
        dp[i][0] = dp_1 + dp_2;
        dp[i][1] = dp_0 + dp_1 + dp_2;
        dp[i][2] = dp_0 + dp_1 + dp_2;
        summ = dp[i][0] + dp[i][1] + dp[i][2];
    }

    cout << summ;
}
