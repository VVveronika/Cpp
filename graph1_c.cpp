#include <iostream>
#include <vector>
#include <string>
using namespace std;

void dfs(int v, vector<bool> & used, vector<vector<int>> & table) {
    used[v] = true;
    for (int to : table[v]) {
        if (!used[to]) {
            dfs(to, used, table);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    string ans = "YES";

    if (n - m != 1) {
        ans = "NO";
    }

    vector<vector<int>> table(n, vector<int> ());

    int start = 0;

    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        start = from - 1;
        table[from - 1].push_back(to - 1);
        table[to - 1].push_back(from - 1);
    }

    vector<bool> used(n);

    dfs(start, used, table);
    for (bool i : used) {
        if (i == false) {
            ans = "NO";
            break;
        }
    }

    cout << ans;

    return 0;
}
