#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> minimums(vector<long long>* val, bool left) {
    vector<long long> values = *val;
    int n = values.size();
    int i = n - 1;
    int delta = -1;
    int border_value = n;

    if (left) {
        i = 0;
        delta = 1;
        border_value = -1;
    }

    vector<int> st(0);
    vector<long long> indexes(n);

    for (int j = 0; j < n; j++) {
        while (!st.empty() && values[st.back()] >= values[i]) {
            st.pop_back();
        }
        if (st.empty()) {
            indexes[i] = border_value;
        } else {
            indexes[i] = st.back();
        }
        st.push_back(i);
        i += delta;
    }

    return indexes;
}

int main() {
    int n;
    cin >> n;

    vector<long long> hs(n);

    for (int i = 0; i < n; i++) {
        cin >> hs[i];
    }

    vector<long long> left_min = minimums(&hs, true);
    vector<long long> right_min = minimums(&hs, false);

    long long max_s = 0;
    long long cur_s = 0;

    for (int i = 0; i < n; i++) {
        cur_s = (right_min[i] - left_min[i] - 1) * hs[i];
        if (cur_s > max_s) {
            max_s = cur_s;
        }
    }

    cout << max_s;
}
