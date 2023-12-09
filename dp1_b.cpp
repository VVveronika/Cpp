#include <vector>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> dp(4, 1);

    int summa = 4;

    if (n == 1) {
        summa = 2;
    }

    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < 4; j++) {
            dp[j] *= 2;
        }
        dp[i % 4] /= 2;
        summa = dp[0] + dp[1] + dp[2] + dp[3];
    }
    cout << summa;
}
