#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;


struct Neighbour {
    int index, weight;
};


struct Vertex {
    long long best_way = INT_MAX;
    bool is_used = false;
    vector<Neighbour> neighbours;
};


void bfs(int start, vector<Vertex>& adj_list) {
    vector<queue<int>> q(3);
    q[0].push(start);

    int count_of_element_in_q = 1;
    int cur_distance = 0;

    while (count_of_element_in_q != 0) {
        int index_of_cur_que = cur_distance % 3;
        queue<int>& cur_queue = q[index_of_cur_que];

        while (!cur_queue.empty()) {
            int cur_index = cur_queue.front();
            cur_queue.pop();
            count_of_element_in_q--;
            if (adj_list[cur_index].is_used) {
                continue;
            }
            adj_list[cur_index].is_used = true;

            for (Neighbour& neighbour : adj_list[cur_index].neighbours) {
                int new_distance = cur_distance + neighbour.weight;
                int neighbour_index = neighbour.index;
                if (new_distance > adj_list[neighbour_index].best_way) {
                    continue;
                }
                adj_list[neighbour_index].best_way = new_distance;
                q[new_distance % 3].push(neighbour_index);
                count_of_element_in_q++;
            }
        }
        cur_distance++;
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
