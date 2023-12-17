#include <vector>
#include <iostream>

using namespace std;

void gen(vector<int>& pref, int n, int k) {
    int len = pref.size();
    if (k == len) {
        for (int i : pref) {
            cout << i << " ";
        }
        cout << '\n';
        return;
    }
    for (int j = 1; j <= n; j++) {
        if (pref.empty() || (j < pref.back() && j >= k - pref.size())) {
            pref.push_back(j);
            gen(pref, j - 1, k);
            pref.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;

    vector<int> pref;
    gen(pref, n , k);
    return 0;
}
