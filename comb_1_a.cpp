#include <vector>
#include <iostream>

using namespace std;

void gen(vector<int>& pref, int n) {
    if (n == pref.size()) {
        for (int i : pref) {
            cout << i;
        }
        cout << endl;
        return;
    }
    pref.push_back(0);
    gen(pref, n);
    pref.pop_back();
    pref.push_back(1);
    gen(pref, n);
    pref.pop_back();
}

int main() {
    int n;
    cin >> n;

    vector<int> pref;
    gen(pref, n);

    return 0;
}
