#include <iostream>
#include <bitset>

using namespace std;

int main() {
    int n, w;
    cin >> n >> w;

    bitset<6250001> bits;
    bits.set(0);

    for (int i = 0; i < n; i++) {
        int cur_w;
        cin >> cur_w;
        bits |= (bits << cur_w);
    }
    
    if (bits.test(w)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
