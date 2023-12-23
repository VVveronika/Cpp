#include <iostream>
#include <vector>

using namespace std;

int main() {
    const int max_size = 30;
    const int min_boys = 4;
    const int min_girls = 1;

    int n, m, t;
    cin >> n >> m >> t;

    vector<vector<unsigned long long>> count_c(max_size + 1, vector<unsigned long long> (max_size + 1));
    count_c[0][0] = 1;

    for (int i = 1; i <= max_size; i++) {
        count_c[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            count_c[i][j] = count_c[i - 1][j] + count_c[i - 1][j - 1];
        }
    }

    unsigned long long ans = 0;

    for (int i = min_boys; i <= n; i++) {
        int g = t - i;
        if (g >= min_girls && g <= m) {
            ans += count_c[n][i] * count_c[m][g];
        }
    }

    cout << ans;
    return 0;
}
