#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k, s;
    cin >> n >> k >> s;

    vector<int> gas_s(s);
    for (int i = 0; i < s; i++) {
        cin >> gas_s[i];
    }

    int cnt = 0;
    int dist = 0;
    int i = 0;

    while (true) {
        int able_to_go = k + dist;
        if (n <= able_to_go) {
            break;
        }
        bool stay = true;
        while (i < s && gas_s[i] <= able_to_go) {
            stay = false;
            i++;
        }
        if (stay) {
            cnt = -1;
            break;
        }
        cnt++;
        dist = gas_s[i - 1];
    }

    cout << cnt;
    return 0;
}