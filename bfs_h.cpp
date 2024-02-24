#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;


struct Neighbour {
    int neighbour_index, weight;
};


struct Vertex {
    long long best_way = INT_MAX;
    bool in_queue = false;
    vector<Neighbour> neighbours;
};


void bfs(int start, vector<Vertex>& adj_list) {
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int cur_vertex_index = q.front();
        Vertex& cur_vertex = adj_list[cur_vertex_index];

        q.pop();
        cur_vertex.in_queue = false;

        for (Neighbour i : cur_vertex.neighbours) {
            Vertex& neighbour_vertex = adj_list[i.neighbour_index];
            if (cur_vertex.best_way + i.weight < neighbour_vertex.best_way) {
                neighbour_vertex.best_way = cur_vertex.best_way + i.weight;
                if (!neighbour_vertex.in_queue) {
                    q.push(i.neighbour_index);
                    neighbour_vertex.in_queue = true;
                }
            }
        }
    }
}

int main() {
    const int start_vertex = 1;

    freopen("kefir.in", "r", stdin);
    freopen("kefir.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<Vertex> adj_list(n + 1);

    for (int i = 1; i <= m; i++) {
        int from_vertex, to_vertex, weight;
        cin >> from_vertex >> to_vertex >> weight;

        Neighbour neighbour = {to_vertex, weight};
        adj_list[from_vertex].neighbours.push_back(neighbour);

        Neighbour reversed_neighbour = {from_vertex, weight};
        adj_list[to_vertex].neighbours.push_back(reversed_neighbour);
    }

    adj_list[start_vertex].best_way = 0;

    bfs(start_vertex, adj_list);

    int answer = adj_list[n].best_way;

    if (answer == INT_MAX) {
        cout << -1;
        return 0;
    }

    cout << answer;

    return 0;
}
