#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    stack<char> way;
    vector<vector<int>> dp(n + 1, vector<int> (m + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int cur_number;
            cin >> cur_number;
            dp[i][j] = cur_number + max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << dp[n][m] << endl;

    int i = n;
    int j = m;

    while (i > 0 && j > 0) {
        if (dp[i - 1][j] >= dp[i][j - 1]) {
            way.push('D');
            i--;
        } else {
            j--;
            way.push('R');
        }
    }
    way.pop();

    while (!way.empty()) {
        cout << way.top() << " ";
        way.pop();
    }

    return 0;
}
