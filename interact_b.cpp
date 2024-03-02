#include <iostream>
#include <vector>

using namespace std;

int guess(int i, int j) {
    cout << "? " << i << ' ' << j << endl;

    int answer = 0;
    cin >> answer;
    return answer;
}

// int guess(int i, int j, vector<int> arr) {
//     cout << "? " << i << ' ' << j << endl;
//     int answer = arr[i - 1] + arr[j - 1];
//     return answer;
// }

void answer_out(vector<int> answer) {
    cout << "! ";
    for (int i : answer) {
        cout << i << ' ';
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    // vector<int> arr = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

    int xy = guess(1, 2);
    int yz = guess(2, 3);
    int xz = guess(1, 3);

    vector<int> answer(n);

    answer[0] = (xz - yz + xy) / 2;
    answer[1] = xy - answer[0];
    answer[2] = yz - answer[1];

    for (int i = 4; i <= n; i++) {
        int pn = guess(i - 1, i);
        answer[i - 1] = pn - answer[i - 2];
    }

    answer_out(answer);

    return 0;
}
