#include <string>
#include <iostream>

using namespace std;

void gen(string& pref, int n) {
    if (n == pref.size()) {
        cout << pref << "\n";
        return;
    }
    pref.push_back('0');
    gen(pref, n);
    pref.pop_back();
    pref.push_back('1');
    gen(pref, n);
    pref.pop_back();
}

int main() {
    int n;
    cin >> n;

    string pref;
    gen(pref, n);

    return 0;
}
