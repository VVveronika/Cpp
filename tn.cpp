#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int exp_n(int n, int divider) {
    int answer = 0;
    int exp = divider;
    while (n / exp > 0) {
        answer += n / exp;
        exp *= divider;
    }
    return answer;
}

int main() {
    const int base_exponent = 1;
    int n, k;
    cin >> n >> k;

    vector<int> null_count;

    for (int i = 2; i * i <= k; i++) {
        int exponent = 0;
        int answer = 0;
        while (k % i == 0) {
            answer = i;
            exponent++;
            k /= i;
        }
        if (answer > 0) {
            null_count.push_back(exp_n(n, answer) / exponent);
        }
    }
    if (k > 1) {
        null_count.push_back(exp_n(n, k) / base_exponent);
    }

    cout << *min_element(null_count.begin(), null_count.end());
    return 0;
}
