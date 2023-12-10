#include <vector>
#include <iostream>

using namespace std;

void gen(vector<int>& pref, int n, int k, int cnt) {
    int len = pref.size();
    if (n == len) {
        for (int i : pref) {
            cout << i;
        }
        cout << endl;
        return;
    }

    if (n - len - 1 >= k - cnt) {
    pref.push_back(0);
    gen(pref, n, k, cnt);
    pref.pop_back();
    }

    if (cnt < k) {
    cnt++;
    pref.push_back(1);
    gen(pref, n, k, cnt);
    pref.pop_back();
    }
}

int main() {
    int n, k, cnt;
    cin >> n >> k;

    vector<int> pref;
    cnt = 0;
    gen(pref, n, k, cnt);

    return 0;
}
