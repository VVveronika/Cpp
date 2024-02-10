#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstdio>
#include <stack>

using namespace std;

struct Edge {
    int to_vertex;
    int weight;
};

struct Vertex {
    int parent;
    int best_distance = INT_MAX;
    vector<Edge> ways;
};

void dijkstra(int start_vertex, vector<Vertex>& graph) {
    graph[start_vertex].best_distance = 0;
    graph[start_vertex].parent = -1;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, start_vertex});

    while (!q.empty()) {
        auto [distance, current_vertex] = q.top();
        q.pop();

        if (graph[current_vertex].best_distance < distance) {
            continue;
        }

        for (auto [to, weight] : graph[current_vertex].ways) {
            int new_distance = graph[current_vertex].best_distance + weight;
            int old_distance = graph[to].best_distance;
            if (new_distance < old_distance) {
                graph[to].best_distance = new_distance;
                graph[to].parent = current_vertex;
                q.push({new_distance, to});
            }
        }
    }
}


int main() {
    int n, m, start_vertex, end_vertex;
    vector<Vertex> graph;

    if (freopen("dist.in", "r", stdin)) {
        cin >> n >> m >> start_vertex >> end_vertex;
        graph.resize(n + 1);

        for (int i = 0; i < m; i++) {
            int from_vertex, to_vertex, weight;
            cin >> from_vertex >> to_vertex >> weight;

            Edge way;
            way.to_vertex = to_vertex;
            way.weight = weight;
            graph[from_vertex].ways.push_back(way);

            Edge reverse_way;
            reverse_way.to_vertex = from_vertex;
            reverse_way.weight = weight;
            graph[to_vertex].ways.push_back(reverse_way);
        }

        fclose(stdin);
    }

    dijkstra(start_vertex, graph);
    int answer = graph[end_vertex].best_distance;

    if (freopen("dist.out", "w", stdout)) {
        if (answer == INT_MAX) {
            cout << -1;
            return 0;
        }

        int parent = graph[end_vertex].parent;
        stack<int> result;
        result.push(end_vertex);
        result.push(parent);
        while (parent != start_vertex) {
            parent = graph[parent].parent;
            result.push(parent);
        }
        int size = result.size();

        cout << answer << "\n";
        cout << result.size() << "\n";
        for (int i = 0; i < size; i++) {
            cout << result.top() << " ";
            result.pop();
        }
        fclose(stdout);
    }
    return 0;
}
