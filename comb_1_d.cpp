#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> vec;
    for (int i = 1; i <= n; i++) {
        vec.push_back(i);
        cout << i;
    }

    while (next_permutation(vec.begin(), vec.end())) {
        cout << endl;
        for (int i : vec) {
            cout << i;
        }
    }

    return 0;
}
