#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <climits>
using namespace std;

struct Vertex {
    int height = -1;
    int x = -1;
    int y = -1;
    bool used = false;
};


void dfs(Vertex& vertex, vector<vector<Vertex>>& field) {
    vertex.used = true;
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for (auto [d_x, d_y] : directions) {
        Vertex& next_vertex = field[vertex.y + d_y][vertex.x + d_x];
        if (next_vertex.used == false && next_vertex.height >= vertex.height) {
            dfs(next_vertex, field);
        }
    }
}


int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<Vertex>> field(n + 2, vector<Vertex> (m + 2));
    multimap<int, Vertex&> field_with_min;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            Vertex& vertex = field[i][j];
            int height;
            cin >> height;
            vertex.height = height;
            vertex.x = j;
            vertex.y = i;
            field_with_min.insert({height, vertex});
        }
    }

    int count_of_stocks = 0;

    for (auto [hight, vertex] : field_with_min) {
        if (vertex.used == false) {
            dfs(vertex, field);
            count_of_stocks++;
        }
    }

    cout << count_of_stocks;
    return 0;
}
