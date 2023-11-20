#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int max_side = max(a, b);
    int min_side = min(a, b);
    int count = 0;

    while (min_side != 0) {
        int last_min_side = min_side;
        int square_num = max_side / min_side;
        min_side = max_side - square_num * min_side;
        max_side = last_min_side;
        count += square_num;
    }

    cout << count;
    return 0;
}
