#include <vector>
#include <iostream>

using namespace std;

extern int cnt = 0;

int fib(int n) {
    cnt++;
    if (n <= 2) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;
    cin >> n;
    fib(n);
    cout << cnt;

    return 0;
}
