#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.size();

    vector<int> pref_function(n);

    for (int i = 1; i < n; i++) {
        int k = pref_function[i - 1];
        while (k > 0 && s[k] != s[i]) {
            k = pref_function[k - 1];
        }
        if (s[k] == s[i]) {
            k++;
        }
        pref_function[i] = k;
    }

    int last_num_of_pref = pref_function[n - 1];
    int delta = n - last_num_of_pref;

    if (last_num_of_pref != 0 && last_num_of_pref % delta == 0) {
        cout << n / delta;
        return 0;
    }

    cout << 0;
    return 0;
}
