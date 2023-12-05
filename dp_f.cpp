#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    const int size = 8;

    int x, y;
    cin >> x >> y;
    y -= 1;

    vector<int> dp(size + 2);
    dp[x] = 1;

    int multiplier = 0;
    int multiplier_1 = x % 2;
    int summa = 1;

    for (int k = y + 1; k < size; k++) {
        multiplier_1 = 1 - multiplier_1;
        summa = 0;
        for (int r = 0; r <= 1; r++) {
            int i = multiplier_1 == 1 ? r : 1 - r;
            multiplier = 1 - multiplier;
            for (int j = i + 1; j <= size; j += 2) {
                dp[j] = (dp[j - 1] + dp[j + 1]) * multiplier;
                summa += dp[j];
            }
        }
    }

    cout << summa;

    return 0;
}
