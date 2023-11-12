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
    int n;
    cin >> n;

    int nod = 0;
    int current_number = 0;

    for (int i = 0; i < n; i++) {
        cin >> current_number;
        nod = gcd(nod, current_number);
    }

    cout << nod;
    return 0;
}
