#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Neighbour {
    int to_vertex;
    int price = 0;
};


struct Vertex {
    long long best_way = INT_MAX;
    int index;
};


int bfs(int start_town_index, int end_town_index, int max_turn, vector<Vertex>& towns, vector<vector<Neighbour>>& neighbours) {
    queue<pair<int, int>> q;

    q.push(make_pair(0, start_town_index));

    pair<int, int> separator = make_pair(-1, -1);
    q.push(separator);

    int answer = INT_MAX;
    int current_turn = 0;

    while (!q.empty() && current_turn <= max_turn) {
        pair<int, int> town_pair = q.front();
        q.pop();

        int town_best_way = town_pair.first;
        if (town_best_way == -1) {
            current_turn++;
            q.push(separator);
            continue;
        }

        int town_index = town_pair.second;
        Vertex& town = towns[town_index];
        // if (town.best_way < town_best_way) {
        //     continue;
        // }

        if (town_index == end_town_index && town_best_way < answer) {
            answer = town_best_way;
        }

        for (auto [neighbour_index, price] : neighbours[town_index]) {
            int new_best_way = town_best_way + price;
            Vertex& neighbour = towns[neighbour_index];
            if (new_best_way < neighbour.best_way) {
                neighbour.best_way = new_best_way;
                q.push(make_pair(new_best_way, neighbour.index));
            }
        }
    }
    return answer;
}


int main() {
    int n, m, k, from_town_index, to_town_index;
    cin >> n >> m >> k >> from_town_index >> to_town_index;
    vector<Vertex> towns(n + 1);
    vector<vector<Neighbour>> neighbours(n + 1, vector<Neighbour> ());
    for (int i = 1; i <= m; i++) {
        int from_vertex, to_vertex, price;
        cin >> from_vertex >> to_vertex>> price;

        Neighbour neighbour;
        neighbour.to_vertex = to_vertex;
        neighbour.price = price;
        neighbours[from_vertex].push_back(neighbour);
        towns[from_vertex].index = from_vertex;
        towns[to_vertex].index = to_vertex;
    }

    int answer = bfs(from_town_index, to_town_index, k, towns, neighbours);

    answer = answer == INT_MAX ? -1 : answer;
    cout << answer;
    return 0;
}
/*
4 5 2 1 4
1 2 1
2 3 1
3 4 1
1 3 3
1 4 5
*/