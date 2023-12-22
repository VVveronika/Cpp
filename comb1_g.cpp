#include <vector>
#include <iostream>

using namespace std;

void gen(vector<int>& pref, int n, int k) {
    if (n == 0) {
        for (int i : pref) {
            cout << i << " ";
        }
        cout << '\n';
        return;
    }
    for (int j = n; j >= 1; j--) {
        if (pref.empty() || (j >= pref.back() && j <= k - pref.back())) {
            pref.push_back(j);
            gen(pref, n - j, k);
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
    int k = n;

    vector<int> pref;
    gen(pref, n, k);
    return 0;
}
