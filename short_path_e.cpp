#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void floid(int n, vector<vector<int>>& graph) {
    for (int station = 0; station < n; station++) {
        for (int from = 0; from < n; from++) {
            for (int to = 0; to < n; to++) {
                int before_station = graph[from][station];
                int after_station = graph[station][to];
                int distance_from_to = graph[from][to];
                bool can_do_better = before_station + after_station < distance_from_to || distance_from_to == 0;
                if ((before_station != 0 && after_station != 0) && can_do_better) {
                    graph[from][to] = before_station + after_station;
                }
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int> (n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];;
        }
    }

    floid(n, graph);
    vector<vector<int>> first_graph = graph;

    floid(n, graph);

    int answer = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (first_graph[i][j] != graph[i][j]) {
                answer = 2;
            } else if (graph[i][j] == 0) {
                answer = 0;
            } else {
                answer = 1;
            }
            cout << answer << " ";
        }
        cout << "\n";
    }

    return 0;
}

/*
3
0 1 -2
1 0 3
1 3 0
*/