#include <iostream>

using namespace std;

int gcd(int n, int m) {
    while (m > 0) {
        n %= m;
        swap(n, m);
    }
    return n;
}

int main() {
    int n, k;
    cin >> n >> k;

    cout << n / gcd(n, k) * k;
    return 0;
}
