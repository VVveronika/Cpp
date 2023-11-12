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
    int a, b, c, d, numerator, denominator, divider;
    cin >> a >> b >> c >> d;

    numerator = a * d + c * b;
    denominator = b * d;
    divider = gcd(numerator, denominator);

    cout << numerator / divider << " " << denominator / divider;

    return 0;
}
