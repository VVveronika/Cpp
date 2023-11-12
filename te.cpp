#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<bool> primes(n + 1, true);
    primes[0] = false;
    primes[1] = false;

    for (int i = 2; i <= n; i++) {
        if (primes[i]) {
            for (int j = i * i; j <= n; j += i) {
                primes[j] = false;
            }
        }
    }

    bool no_primes = true;
    for (int i = m; i <= n; i++) {
        if (primes[i]) {
            cout << i << endl;
            no_primes = false;
        }
    }

    if (no_primes) {
        cout << -1;
    }

    return 0;
}
