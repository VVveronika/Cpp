#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int border(vector<int>& vec, int num, bool find_left) {
    int L = 0;
    int R = vec.size() - 1;

    while (R - L > 1) {
        int m = (L + R) / 2;
        int cur_first = vec[m];
        if ((find_left && num >= cur_first) || (!find_left && num > cur_first)) {
            L = m;
        } else {
            R = m;
        }
    }

    int ans = find_left? L : R;
    if (vec[ans] != num) {
        return -1;
    } else {
        return ans;
    }
}

int main() {
    const int limit = 1000000001;
    int n;
    int k;
    cin >> n;
    vector<int> first_arr(n + 2);

    for (int i = 0; i < n; i++) {
        cin >> first_arr[i];
    }

    first_arr[n] = -limit;
    first_arr[n + 1] = limit;

    cin >> k;
    vector<int> second_arr(k);

    for (int j = 0; j < k; j++) {
        cin >> second_arr[j];
    }

    sort(first_arr.begin(), first_arr.end());

    int ans_l;
    int ans_r;
    for (int i = 0; i < k; i++) {
        int cur_second = second_arr[i];
        ans_l = border(first_arr, cur_second, true);
        if (ans_l == -1) {
            cout << 0 << " ";
            continue;
        }
        ans_r = border(first_arr, cur_second, false);
        cout << ans_l - ans_r + 1 << " ";
    }
    return 0;
}
