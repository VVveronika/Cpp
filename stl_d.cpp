#include <set>
#include <iostream>
#include <string>
#include <map>
using namespace std;

class Sets {
 private:
        map<int, multiset<long long>> sets;
        map<long long, multiset<int>> sets_1;

 public:
        void add(int s, long long e) {
            sets[s].insert(e);
            sets_1[e].insert(s);
        }

        void del(int s, long long e) {
            sets[s].erase(sets[s].find(e));
            sets_1[e].erase(sets_1[e].find(s));
        }

        void clear(int s) {
            for (long long i : sets[s]) {
                sets_1[i].erase(sets_1[i].find(s));
            }
            sets[s].clear();
        }

        void listset(int s) {
            if (sets[s].empty()) {
                cout << -1;
            } else {
                for (long long i : sets[s]) {
                    cout << i << " ";
                }
            }
            cout << endl;
        }

        void listsetsof(long long e) {
            if (sets_1[e].empty()) {
                cout << -1;
            } else {
                for (long long i : sets_1[e]) {
                    cout << i << " ";
                }
            }
            cout << endl;
        }
};

int main() {
    long long n, e;
    int m, k, s;

    cin >> n >> m >> k;

    Sets sets;

    for (int i = 0; i < k; i++) {
        string command;
        cin >> command;

        if (command == "ADD") {
            cin >> s >> e;
            sets.add(s, e);
        } else if (command == "DELETE") {
            cin >> s >> e;
            sets.del(s, e);
        } else if (command == "CLEAR") {
            cin >> s;
            sets.clear(s);
        } else if (command == "LISTSET") {
            cin >> s;
            sets.listset(s);
        } else if (command == "LISTSETSOF") {
            cin >> e;
            sets.listsetsof(e);
        }
    }
    return 0;
}

/*
9223372036854775807 10
9
ADD 1 9
ADD 1 9
ADD 1 9223372036854775807
LISTSET 1
LISTSETSOF 1
DELETE 1 9
LISTSET 2
CLEAR 1
LISTSET 1
*/