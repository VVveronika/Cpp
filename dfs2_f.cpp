#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <cmath>

using namespace std;

struct Apple {
    int x, y, z, r;
    bool is_flying = false;
};


int main() {
    const int start_apple = 1;
    int n;
    cin >> n;

    vector<Apple> apples(n + 1);

    for (int i = start_apple; i <= n; i++) {
        Apple& cur_apple = apples[i];
        cin >> cur_apple.x >> cur_apple.y >> cur_apple.z >> cur_apple.r;
    }

    apples[start_apple].is_flying = true;

    int count_of_flying_apples = 1;

    queue<int> q;
    q.push(start_apple);

    while (!q.empty()) {
        int apple_index = q.back();
        Apple apple = apples[apple_index];
        q.pop();

        for (int i = start_apple + 1; i <= n; i++) {
            Apple& neibour_apple = apples[i];
            int distance = pow((apple.x - neibour_apple.x), 2) + pow((apple.y - neibour_apple.y), 2);
            if (!neibour_apple.is_flying && apple.z >= neibour_apple.z && pow(apple.r + neibour_apple.r, 2) >= distance) {
                neibour_apple.is_flying = true;
                count_of_flying_apples++;
                q.push(i);
            }
        }
    }

    cout << count_of_flying_apples << '\n';
    for (int i = start_apple; i <= n; i++) {
        if (apples[i].is_flying) {
            cout << i << ' ';
        }
    }

    return 0;
}
