#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
    int number, squere_root_number;
    cin >> number;
    squere_root_number = sqrt(number);
    string answer;
    answer = "prime";

    for (int i = 2; i <= squere_root_number; i++) {
        if (number % i == 0) {
            answer = "composite";
            break;
        }
    }
    cout << answer;
}
