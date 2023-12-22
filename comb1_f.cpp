#include <vector>
#include <iostream>

using namespace std;

void gen(vector<int>& pref, int n) {
    if (n == 0) {
        for (int i : pref) {
            cout << i << " ";
        }
        cout << '\n';
        return;
    }
    for (int j = 1; j <= n; j++) {
        if (pref.empty() || j <= pref.back()) {
            pref.push_back(j);
            gen(pref, n - j);
            pref.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;

    vector<int> pref;
    gen(pref, n);
    return 0;
}
