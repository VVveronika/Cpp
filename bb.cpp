#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int k;
    cin >> n >> k;
    vector<int> first_arr(n);
    vector<int> second_arr(k);

    for (int i = 0; i < n; i++) {
        cin >> first_arr[i];
    }
    for (int j = 0; j < k; j++) {
        cin >> second_arr[j];
    }

    for (int i = 0; i < k; i++) {
        int L = 0;
        int R = n - 1;
        int cur_second = second_arr[i];
        while (R - L > 1) {
            int m = (L + R) / 2;
            int cur_first = first_arr[m];
            if (cur_second >= cur_first) {
                L = m;
            } else {
                R = m;
            }
        }
        int value_r = first_arr[R];
        int value_l = first_arr[L];
        if (value_r - cur_second < cur_second - value_l) {
            cout << value_r;
        } else {
            cout << value_l;
        }
        cout << endl;
    }
    return 0;
}