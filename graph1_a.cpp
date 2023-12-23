#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int c_from_to = 2;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int> (n));

    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        matrix[from - 1][to - 1] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
