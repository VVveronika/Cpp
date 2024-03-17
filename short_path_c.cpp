#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int MAX_I = 1000000;

struct Vertex {
    long long best_way = MAX_I;
    bool in_queue = false;
    bool is_fuel_in_canister = false;
    int price_of_fuel;
    int price_of_fuel_in_canister = 0;
    int fuel_status = 0;
    int index;
    vector<int> neighbours;
};

void bfs(vector<Vertex>& towns) {
    queue<int> q;

    int start_vertex = 1;
    towns[start_vertex].best_way = 0;
    q.push(start_vertex);
    towns[start_vertex].in_queue = true;

    while (!q.empty()) {
        Vertex& cur_town = towns[q.front()];
        q.pop();
        cur_town.in_queue = false;
        if (cur_town.price_of_fuel == -1) {
            continue;
        }

        for (int neighbour_index : cur_town.neighbours) {
            Vertex& neighbour = towns[neighbour_index];
            int cur_fuel_status = cur_town.fuel_status;
            int next_price_of_fuel_in_canister = 0;
            int next_best_way = cur_town.best_way;
            int next_fuel_status = 0;
            bool next_is_fuel_in_canister = false;
            bool refuel_now = cur_town.price_of_fuel < neighbour.price_of_fuel;

            if (cur_fuel_status == 0) {
                next_best_way = next_best_way + cur_town.price_of_fuel;
                if (refuel_now) {
                    next_fuel_status = 1;
                    next_price_of_fuel_in_canister = cur_town.price_of_fuel;
                    next_is_fuel_in_canister = true;
                } else {
                    next_fuel_status = 0;
                    next_price_of_fuel_in_canister = 0;
                }
            } else {
                next_best_way = next_best_way + cur_town.price_of_fuel_in_canister;
                if (refuel_now) {
                    next_fuel_status = 1;
                    next_price_of_fuel_in_canister = cur_town.price_of_fuel;
                    next_is_fuel_in_canister = true;
                } else {
                    next_fuel_status = 0;
                    next_price_of_fuel_in_canister = 0;
                }
            }

            int past_delta = neighbour.is_fuel_in_canister ? neighbour.price_of_fuel_in_canister : neighbour.price_of_fuel;
            int next_delta = next_is_fuel_in_canister ? next_price_of_fuel_in_canister : neighbour.price_of_fuel;

            if (neighbour.best_way + past_delta > next_best_way + next_delta) {
                neighbour.best_way = next_best_way;
                neighbour.is_fuel_in_canister = next_is_fuel_in_canister;
                neighbour.price_of_fuel_in_canister = next_price_of_fuel_in_canister;
                neighbour.fuel_status = next_fuel_status;
                if (!neighbour.in_queue) {
                    q.push(neighbour_index);
                    neighbour.in_queue = true;
                }
            }
        }
    }
}


int main() {
    int n, m;
    cin >> n;

    vector<Vertex> towns(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> towns[i].price_of_fuel;
        towns[i].index = i;
    }
    towns[n].price_of_fuel = -1;
    cin >> m;

    for (int i = 1; i <= m; i++) {
        int from_vertex, to_vertex;
        cin >> from_vertex >> to_vertex;

        towns[from_vertex].neighbours.push_back(to_vertex);
        towns[to_vertex].neighbours.push_back(from_vertex);
    }

    bfs(towns);

    int answer = towns[n].best_way;
    if (answer == MAX_I) {
        answer = -1;
    }

    cout << answer;

    return 0;
}
