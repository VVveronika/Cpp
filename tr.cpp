#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int max_div = 1;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            max_div = n / i;
            break;
        }
    }

    cout << max_div << " " << n - max_div;
}
