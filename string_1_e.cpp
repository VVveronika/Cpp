#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    string str;
    cin >> str;

    string reversed_str = str;
    reverse(reversed_str.begin(), reversed_str.end());

    string new_str = str + reversed_str;

    n = 2 * n;

    int L = 0;
    int R = 0;

    vector<int> n_function(n);

    for (int i = 1; i < n; i++) {
        int& nf = n_function[i];
        nf = max(0, min(n_function[i - L], R - i));

        while (new_str[i + nf] == new_str[nf]) {
            nf++;
        }
        if (i + nf > R) {
            L = i;
            R = i + nf;
        }

        // cout << nf << ' ';
        n_function[i] = nf;
    }

    for (int i = n - 1; i >= n / 2; i--) {
        cout << n_function[i] << ' ';
    }

    return 0;
}
