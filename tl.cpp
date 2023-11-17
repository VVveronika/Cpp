#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> primes;
    vector<int> minimal_dividers(n);
    unordered_set<int> primes_set;

    int primes_size = 0;
    for (int i = 2; i < n; i++) {
        if (minimal_dividers[i] == 0) {
            primes.push_back(i);
            primes_set.insert(i);
            primes_size++;
            minimal_dividers[i] = i;
        }

        int j = 0;
        while (j < primes_size && i * primes[j] < n && primes[j] <= minimal_dividers[i]) {
            minimal_dividers[i * primes[j]] = primes[j];
            j++;
        }
    }

    auto primes_end = primes_set.end();
    for (auto prime : primes_set) {
        int difference = n - prime;
        if (primes_set.find(difference) != primes_end) {
            cout << prime << " " << difference;
            break;
        }
    }
    return 0;
}
