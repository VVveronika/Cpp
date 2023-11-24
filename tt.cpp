#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    a = max(a, 3);

    vector<int> min_dividers(b + 3);
    vector<int> primes;

    int primes_num = 0;

    for (int i = 2; i <= b + 2; i++) {
        if (min_dividers[i] == 0) {
            primes.push_back(i);
            min_dividers[i] = i;
            primes_num++;
        }
        for (int j = 0; j < primes_num && primes[j] <= min_dividers[i] && primes[j] * i <= b + 2; j++) {
            min_dividers[primes[j] * i] = primes[j];
        }
    }

    int count = 0;
    for (int i = primes_num - 1; primes[i] >= a && i >= 0 ; i--) {
        int cur_prime = primes[i];
        if (cur_prime <= b && (min_dividers[cur_prime - 2] == cur_prime - 2 || min_dividers[cur_prime + 2] == cur_prime + 2)) {
            count++;
        }
    }
    cout << count;
    return 0;
}
