#include <vector>
#include <iostream>

using namespace std;

void gen(vector<int>& pref, int n, int m) {
    if (n == 1) {
        cout << pref[0];
        for (int i = 1; i < pref.size(); i++) {
            cout << '*' << pref[i];
        }
        cout << '\n';
        return;
    }
    for (int j = m; j <= n; j++) {
        if ((n % j == 0) && (pref.empty() || j >= pref.back())) {
            pref.push_back(j);
            gen(pref, n / j, m);
            pref.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;

    vector<int> pref;
    gen(pref, n, m);
    return 0;
}
