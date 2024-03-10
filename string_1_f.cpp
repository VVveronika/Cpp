#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string s_in, s_witn_shift;
    cin >> s_in >> s_witn_shift;

    if (s_in == s_witn_shift) {
        cout << 0;
        return 0;
    }

    string s = s_witn_shift + '#' + s_in + s_in;
    int n_for_pref = s.size();
    int n = s_in.size();

    vector<int> pref_function(n_for_pref);

    for (int i = 1; i < n_for_pref; i++) {
        int k = pref_function[i - 1];
        while (k > 0 && s[k] != s[i]) {
            k = pref_function[k - 1];
        }
        if (s[k] == s[i]) {
            k++;
        }
        pref_function[i] = k;
    }

    int index_of_entry = -1;

    for (int i = 0; i < n_for_pref; i++) {
        if (pref_function[i] == n) {
            index_of_entry = i - 2 * n;
            break;
        }
    }
    if (index_of_entry == -1) {
        cout << -1;
        return 0;
    }
    cout << n - index_of_entry;
    return 0;
}
