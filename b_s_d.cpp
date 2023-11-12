#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> minimums(vector<int>& hight, bool left) {
    // Находит левые или правые минимумы в зависимости от значения переменной left
    int hight_size = hight.size();
    int i = hight_size - 1;
    int delta = -1;
    int border_value = hight_size;

    if (left) {
        i = 0;
        delta = 1;
        border_value = -1;
    }

    stack<int> st;
    vector<int> indexes(hight_size);

    for (int j = 0; j < hight_size; j++) {
        while (!st.empty() && (hight)[st.top()] >= (hight)[i]) {
            st.pop();
        }
        if (st.empty()) {
            indexes[i] = border_value;
        } else {
            indexes[i] = st.top();
        }
        st.push(i);
        i += delta;
    }

    return indexes;
}

int maximal_square(vector<int>& hight) {
    // Находит максимальную площадь прямоугольника для заданных в hight высот
    vector<int> left_min = minimums(hight, true);
    vector<int> right_min = minimums(hight, false);

    int max_square = 0;
    int hight_size = hight.size();

    for (int i = 0; i < hight_size; i++) {
        max_square = max(max_square, (right_min[i] - left_min[i] - 1) * (hight)[i]);
    }

    return max_square;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> hight(m);
    int max_answer = 0;
    int color;

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            cin >> color;
            if (color == 0) {
                hight[i]++;
            } else {
                hight[i] = 0;
            }
        }
        max_answer = max(max_answer, maximal_square(hight));
    }

    cout << max_answer;
}