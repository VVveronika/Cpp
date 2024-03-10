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

    for (int i = 1; i < n; i++) {
        int delta = i - j;
        int& nf = n_function[i];

        if (n_function[delta] + delta < n_function[j]) {
            nf = n_function[i - j];
        } else {
            while (i + nf < n && s[i + nf] == s[nf]) {
                nf++;
            }
            if (i + nf > j + n_function[j]) {
                j = i;
            }
        }
    }

    n_function[0] = n;

    for (int i : n_function) {
        cout << i << ' ';
    }

    return 0;
}
