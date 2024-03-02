#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.size();

    vector<int> prefix_f(n);

    for (int i = 1; i < n; i++) {
        int k = prefix_f[i - 1];
        while (k > 0 && s[k] != s[i]) {
            k = prefix_f[k - 1];
        }
        if (s[k] == s[i]) {
            k++;
        }
        prefix_f[i] = k;
    }

    for (int i : prefix_f) {
        cout << i << ' ';
    }

    return 0;
}
