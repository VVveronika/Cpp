#include <iostream>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

int close_number(int position, vector<int>& vec) {
    int min_distance = 55;
    int next_position = 0;

    for (int i : vec) {
        if (abs(i - position) < min_distance) {
            min_distance = abs(i - position);
            next_position = i;
        }
    }
    return next_position;
}

int main() {
    int n;
    cin >> n;

    map<int, vector<int>> fish_house;
    vector<int> cur_time(n);

    for (int i = 0; i < n; i++) {
        int population;
        cin >> population;
        int born_time = max(1000 - population, 1);
        fish_house[born_time].push_back(i);
        cur_time[i] = born_time;
    }

    int time = 0;
    int position = 0;
    int answer = 0;

    while (true) {
        auto close_fish_house = fish_house.begin();
        int birth_time = close_fish_house->first;
        vector<int> fish_house_number = close_fish_house->second;
        int next_fish_house = close_number(position, fish_house_number);

        time += abs(next_fish_house - position);
        position = next_fish_house;

        if (fish_house_number.size() > 1 || time > birth_time) {
            answer = birth_time;
            break;
        } else if (time < birth_time) {
            time = birth_time;
        }

        fish_house[birth_time + max(1, --cur_time[position])].push_back(fish_house_number[0]);
        fish_house.erase(close_fish_house->first);
    }

    cout << answer;
    return 0;
}
