#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {

    list<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

    int cnt = 0;
    string answer;
    for (int i : primes) {
        cout << i << endl;
        cin >> answer;
        if (answer == "yes") {
            cnt++;
            primes.push_back(i * i);
        }

        if (cnt == 2) {
            cout << "composite" << endl;
            return 0;
        }
    }

    cout << "prime" << endl;
    return 0;
}
