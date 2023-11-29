#include <vector>
#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> numbers(n);
    multiset<int> window;

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    int j = 0;
    for (int i = 0; i < n; i++) {
        window.insert(numbers[i]);
        if (window.size() == k) {
            cout << *window.begin() << " ";
            window.erase(window.find(numbers[j]));
            j++;
        }
    }
}
