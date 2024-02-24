#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a;
    cin >> a;

    vector<int> bit(8);

    int cnt = 7;

    while (a != 0) {
        bit[cnt] = a % 2;
        cnt--;
        a /= 2;
    }

    for (int i : bit) {
        cout << i;
    }
}
