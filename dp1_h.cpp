#include <vector>
#include <iostream>

using namespace std;

int turn_number(vector<vector<int>>& horse_turn, vector<vector<int>>& dp, int i, int j, int n, int m) {
    int ans = 0;
    for (int k = 0; k < horse_turn.size(); k++) {
        int next_i = i + horse_turn[k][0];
        int next_j = j + horse_turn[k][1];
        if (0 <= next_i && next_i < n && 0 <= next_j && next_j < m) {
            ans += dp[next_i][next_j];
        }
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dp(n, vector<int> (m));
    dp[0][0] = 1;
    vector<vector<int>> horse_turn = {{-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {1, 2}};

    int i = 0;
    int j = 0;
    while (i < n - 1 || j < m) {
        int i1 = i;
        int j1 = j;
        while (i1 >= 0 && j1 < m) {
            dp[i1][j1] += turn_number(horse_turn, dp, i1, j1, n, m);
            i1--;
            j1++;
        }
        if (i < n - 1) {
            i++;
        } else {
            j++;
        }
    }

    cout << dp[n - 1][m - 1];
    return 0;
}
