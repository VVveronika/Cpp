#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    const int size = 8;

    int x, y;
    cin >> x >> y;
    y -= 1;

    vector<vector<int>> dp(size, vector<int> (size + 2));
    dp[y][x] = 1;

    int summa;
    for (int i = y + 1; i < size; i++) {
        summa = 0;
        for (int j = 1; j <= size; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
            summa += dp[i][j];            
        }
    }

    cout << summa;

    return 0;
}
