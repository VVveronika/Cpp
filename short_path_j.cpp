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
    bool in_queue = false;
    int index;
    int turn = 0;
    vector<Neighbour> neighbours;
};


void bfs (int start_town_index, int max_turn, vector<Vertex>& towns) {
    queue<int> q;
    q.push(start_town_index);
    q.push(-1);
    Vertex& town = towns[start_town_index];
    town.in_queue = true;
    town.best_way = 0;
    
    while (!q.empty() && max_turn > 0) {
        int town_index = q.front();
        q.pop();
        if (town_index == -1) {
            max_turn--;
            q.push(-1);
            continue;
        }
        town = towns[town_index];
        town.in_queue = false;
        for (auto [neighbour_index, price] : town.neighbours) {
            Vertex& neighbour = towns[neighbour_index];
            if (town.best_way + price < neighbour.best_way) {
                neighbour.best_way = town.best_way + price;
                neighbour.turn = town.turn + 1;
                if (!neighbour.in_queue) {
                    q.push(neighbour_index);
                    neighbour.in_queue = true;
                }
            }
        }
    }

}


int main() {
    int n, m, k, from_town_index, to_town_index;
    cin >> n >> m >> k >> from_town_index >> to_town_index;
    vector<Vertex> towns(n + 1);

    for (int i = 1; i <= m; i++) {
        int from_vertex, to_vertex, price;
        cin >> from_vertex >> to_vertex>> price;
        // if (to_vertex == from_town_index) {
        //     price = 0;
        // }

        Neighbour neighbour;
        neighbour.to_vertex = to_vertex;
        neighbour.price = price;
        towns[from_vertex].neighbours.push_back(neighbour);
        towns[from_vertex].index = from_vertex;
        towns[to_vertex].index = to_vertex;
    }

    bfs(from_town_index, k, towns);

    int answer = -1;
    if (towns[to_town_index].turn <= k) {
        answer = towns[to_town_index].best_way;
    }
    cout << answer;
    return 0;
}