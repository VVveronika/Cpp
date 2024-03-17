#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    int n = s.size();

    vector<int> n_function(n);

    int j = 0;

    cout << n << ' ';

    int L = 0;
    int R = 0;

    for (int i = 1; i < n; i++) {
        int& nf = n_function[i];
        nf = max(0, min(n_function[i - L], R - i));

        // int delta = i - j;

        // if (n_function[delta] + delta < n_function[j]) {
        //     nf = n_function[i - j];
        // } else {
        while (s[i + nf] == s[nf]) {
            nf++;
        }
        if (i + nf > R) {
            L = i;
            R = i + nf;
        }
        // }
        cout << nf << ' ';
    }

    // n_function[0] = n;

    // for (int i : n_function) {
    //     cout << i << ' ';
    // }

    return 0;
}
