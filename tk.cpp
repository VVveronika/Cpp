#include <iostream>
#include <vector>

using namespace std;

int gcd(int n, int m) {
    while (m > 0) {
        n %= m;
        swap(n, m);
    }
    return n;
}

int main() {
    int n, x1, y1;

    cin >> n;
    cin >> x1 >> y1;
    int x0 = x1;
    int y0 = y1;

    long long count = 0;

    for (int i = 0; i < n; i++) {
        int x2, y2, delta_x, delta_y;
        if (i == n - 1) {
            x2 = x0;
            y2 = y0;
        } else {
            cin >> x2 >> y2;
        }
        delta_x = abs(x2 - x1);
        delta_y = abs(y2 - y1);
        count += gcd(delta_x, delta_y);
        x1 = x2;
        y1 = y2;
    }

    cout << count;

    return 0;
}
