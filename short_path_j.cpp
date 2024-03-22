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
    // bool in_queue = false;
    int index;
    int turn = 0;
    // vector<Neighbour> neighbours;
};


int bfs(int start_town_index, int end_town_index, int max_turn, vector<Vertex>& towns, vector<vector<Neighbour>>& neighbours) {
    queue<Vertex> q;
    // q.push(-1);
    Vertex& town = towns[start_town_index];
    // town.in_queue = true;
    town.best_way = 0;
    q.push(towns[start_town_index]);
    Vertex separator;
    separator.best_way = -1;
    q.push(separator);
    int answer = INT_MAX;

    while (!q.empty() && max_turn >= 0) {
        town = q.front();
        q.pop();
        if (town.best_way == -1) {
            max_turn--;
            q.push(separator);
            continue;
        }
        if (town.index == end_town_index && town.best_way < answer) {
            answer = town.best_way;
        }
        // town = towns[town_index];
        // town.in_queue = false;
        for (auto [neighbour_index, price] : neighbours[town.index]) {
            Vertex neighbour = towns[neighbour_index];
            if (town.best_way + price < neighbour.best_way) {
                neighbour.best_way = town.best_way + price;
                neighbour.turn = town.turn + 1;
                // if (!neighbour.in_queue) {
                    // neighbour.in_queue = true;
                q.push(neighbour);
                // }
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
        // if (to_vertex == from_town_index) {
        //     price = 0;
        // }

        Neighbour neighbour;
        neighbour.to_vertex = to_vertex;
        neighbour.price = price;
        neighbours[from_vertex].push_back(neighbour);
        // towns[from_vertex].neighbours.push_back(neighbour);
        towns[from_vertex].index = from_vertex;
        towns[to_vertex].index = to_vertex;
    }

    int answer = bfs(from_town_index, to_town_index, k, towns, neighbours);

    answer = answer == INT_MAX ? -1 : answer;
    // if (towns[to_town_index].turn <= k) {
    //     answer = towns[to_town_index].best_way;
    // }
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
