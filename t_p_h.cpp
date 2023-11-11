#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int releases_count = n * k;
    vector<pair<int, int>> releases_time(releases_count);

    for (int i = 0; i < releases_count; i++) {
        int release_time;
        cin >> release_time;
        releases_time[i] = make_pair(release_time, i / n);
    }

    sort(releases_time.begin(), releases_time.end());

    vector<int> answer(k, -n * (n - 1) / 2);

    for (int i = 0; i < releases_count; i++) {
        answer[releases_time[i].second] += i;
    }

    for (int i : answer) {
        cout << i << " ";
    }
    return 0;
}
