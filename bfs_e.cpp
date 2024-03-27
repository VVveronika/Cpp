#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    string number;
    cin >> number;

    int k;
    cin >> k;

    int count_of_valid_val;
    cin >> count_of_valid_val;

    vector<int> valid_val(count_of_valid_val);
    for (int i = 0; i < count_of_valid_val; i++) {
        cin >> valid_val[i];
    }

    sort(valid_val.begin(), valid_val.end());

    int remainder = 0;

    for (char i : number) {
        int digit = int(i) - 48;
        remainder = (remainder * 10 + digit) % k;
    }

    queue<pair<int, string>> q;

    q.push({remainder, ""});
    q.push({-1, "#"});

    string answer = "-1";

    while (count_of_valid_val >= 0) {
        auto [cur_reminder, additive] = q.front();
        q.pop();
        if (additive == "#") {
            count_of_valid_val--;
            continue;
        }
        if (cur_reminder % k == 0) {
            answer = number + additive;
            break;
        }
        for (int i : valid_val) {
            q.push({(cur_reminder * 10 + i) % k, additive + to_string(i)});
        }
        q.push({-1, "#"});
    }
    cout << answer;
    return 0;
}
