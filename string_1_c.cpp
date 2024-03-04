#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    string string_for_prefex = t + '#' + s;

    int n = s.size();
    int m = t.size();

    int num_for_prefex = n + m + 1;

    vector<int> prefix_f(num_for_prefex);

    for (int i = 1; i < num_for_prefex; i++) {
        int k = prefix_f[i - 1];
        while (k > 0 && string_for_prefex[k] != string_for_prefex[i]) {
            k = prefix_f[k - 1];
        }
        if (string_for_prefex[k] == string_for_prefex[i]) {
            k++;
        }
        prefix_f[i] = k;
    }

    for (int i = 0; i < num_for_prefex; i++) {
        if (prefix_f[i] == m) {
            cout << i - m * 2 << ' ';
        }
    }

    return 0;
}
