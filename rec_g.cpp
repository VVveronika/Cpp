#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    int len = 3;
    int k = 0;
    while (len < n) {
        k++;
        len = len * 2 + k + 3;
    }

    while (k >= 0) {
        int center_len = 3 + k;
        int side_len = (len - center_len) / 2;
        if (n == side_len + 1) {
            cout << "m";
            break;
        } else if (n > side_len + 1 && n <= side_len + center_len) {
            cout << "o";
            break;
        } else {
            n = n > side_len + center_len ? n - center_len - side_len : n;
            len = side_len;
            k--;
        }
    }

    return 0;
}
