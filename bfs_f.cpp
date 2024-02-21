#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;


struct Vertex {
    int parent = 0;
    bool is_visited = false;
};


int main() {
    int final_number, start_number;

    cin >> start_number >> final_number;

    vector<Vertex> numbers(10000);
    numbers[start_number].is_visited = true;

    queue<int> q;
    q.push(start_number);

    while (!q.empty()) {
        int cur_number = q.front();
        q.pop();

        if (cur_number == final_number) {
            break;
        }

        int first_digit = cur_number / 1000;
        if (first_digit != 9) {
            int new_number = cur_number + 1000;
            if (!numbers[new_number].is_visited) {
                numbers[new_number].parent = cur_number;
                q.push(new_number);
                numbers[new_number].is_visited = true;
            }
        }

        int last_digit = cur_number % 10;
        if (last_digit != 1) {
            int new_number = cur_number - 1;
            if (!numbers[new_number].is_visited) {
                numbers[new_number].parent = cur_number;
                q.push(new_number);
                numbers[new_number].is_visited = true;
            }
        }

        int new_number_left = (cur_number - first_digit * 1000) * 10 + first_digit;
        if (!numbers[new_number_left].is_visited) {
            numbers[new_number_left].parent = cur_number;
            q.push(new_number_left);
            numbers[new_number_left].is_visited = true;
        }

        int new_number_right = (cur_number - last_digit) / 10 + last_digit * 1000;
        if (!numbers[new_number_right].is_visited) {
            numbers[new_number_right].parent = cur_number;
            q.push(new_number_right);
            numbers[new_number_right].is_visited = true;
        }
    }

    stack<int> answer;

    int parent = final_number;
    answer.push(final_number);

    while (parent != start_number) {
        parent = numbers[parent].parent;
        answer.push(parent);
    }

    while (!answer.empty()) {
        cout << answer.top() << '\n';
        answer.pop();
    }
    return 0;
}

