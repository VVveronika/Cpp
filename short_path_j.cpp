#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge {
    int from_vertex, to_vertex, weight;
};


void bellman(int start_vertex, int max_turn, vector<Edge>& edges, vector<int>& distances) {
    int n = distances.size();
    for (int i = 0; i < max_turn; i++) {
        for (auto edge : edges) {
            int from_distance = distances[edge.from_vertex];
            int new_distance = from_distance + edge.weight;
            if (new_distance < distances[edge.to_vertex] && from_distance < INT_MAX) {
                distances[edge.to_vertex] = new_distance;
            }
        }
    }
}


int main() {
    int n, m, k, from_town_index, to_town_index;
    cin >> n >> m >> k >> from_town_index >> to_town_index;

    vector<Edge> edges(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> edges[i].from_vertex >> edges[i].to_vertex >> edges[i].weight;
    }

    vector<int> distances(n + 1, INT_MAX);
    distances[from_town_index] = 0;

    bellman(from_town_index, k, edges, distances);

    int answer = distances[to_town_index];
    cout << (answer == INT_MAX ? -1 : answer) << " ";

    return 0;
}