#include <iostream>

using namespace std;

int main() {
    int number, i;
    cin >> number;

    int count_of_multipliers = 2;

    for (i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            count_of_multipliers += 2;
        }
    }
    i--;
    if (i * i == number) {
        count_of_multipliers--;
    }

    cout << count_of_multipliers;
    return 0;
}
