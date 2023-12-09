#include <vector>
#include <iostream>

using namespace std;

void gen(vector<int>& pref, int n, int k) {
    if (n == pref.size()) {
        for (int i : pref) {
            cout << i;
        }
        cout << endl;
        return;
    }
    for (int j = 0; j < k; j++) {
    pref.push_back(j);
    gen(pref, n, k);
    pref.pop_back();
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> pref;
    gen(pref, n, k);

    return 0;
}
