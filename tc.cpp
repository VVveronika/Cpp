#include <iostream>
#include <string>

using namespace std;

int main() {
    int number;
    cin >> number;

    string multiplier = "";

    for (int i = 2; i * i <= number; i++) {
        int exponent = 0;
        int answer = 0;
        while (number % i == 0) {
            answer = i;
            exponent++;
            number /= i;
        }
        if (answer > 0) {
            cout << multiplier << answer;
            multiplier = "*";
        }
        if (exponent > 1) {
            cout << "^" << exponent;
        }
    }
    if (number > 1) {
        cout << multiplier << number;
    }
}
