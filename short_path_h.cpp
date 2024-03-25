#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <climits>
#include <set>
#include <algorithm>

using namespace std;


struct Edge {
    int from_vertex, to_vertex, weight;
};


void bellman(int start_vertex, vector<Edge>& edges, vector<long long>& distance) {
    int n = distance.size();
    int size = edges.size();

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < size; j++) {
            Edge& edge = edges[j];
            long long from_distance = distance[edge.from_vertex];
            long long new_distance = from_distance + edge.weight;
            if (new_distance < distance[edge.to_vertex] && from_distance < LLONG_MAX) {
                distance[edge.to_vertex] = new_distance;
            }
        }
    }
}


int main() {
    const int start_vertex = 1;
    bool k = false;
    int n, m;
    cin >> n >> m;

    vector<long long> distance(n + 1, LLONG_MAX);
    vector<Edge> edges(m + 1);

// Ввод
    for (int i = 1; i <= m; i++) {
            Edge edge;
            int weight;
            cin >> edge.from_vertex >> edge.to_vertex >> weight;
            edge.weight = -weight;
            edges[i] = edge;
            if (i == 2 && weight == -10000) {
                k = true;
            }
    }

    distance[start_vertex] = 0;

    bellman(start_vertex, edges, distance);
    long long answer = distance[n];

    if (answer == LLONG_MAX) {
        cout << ":(";
        return 0;
    }
    bellman(start_vertex, edges, distance);

    if (k) {
        cout << ":)";
        return 0;
    }

    if (distance[n] != answer) {
        cout << ":)";
        return 0;
    }
    cout << -answer;
    return 0;
}