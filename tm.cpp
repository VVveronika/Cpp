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
    int n, m;
    cin >> n >> m;

    cout << gcd(n - 1, m - 1) + 1;
    return 0;
}
