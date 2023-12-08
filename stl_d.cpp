#include <set>
#include <iostream>
#include <string>
#include <map>
using namespace std;

class Sets {
 private:
        map<long long, set<long long>> sets;
        map<long long, set<long long>> sets_1;

 public:
        void add(long long e, long long s) {
            sets[s].insert(e);
            sets_1[e].insert(s);
        }

        void del(long long e, long long s) {
            sets[s].erase(e);
            sets_1[e].erase(s);
        }

        void clear(long long s) {
            for (long long i : sets[s]) {
                sets_1[i].erase(s);
            }
            sets[s].clear();
        }

        void listset(long long s) {
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
    long long n, e, m, k, s;

    cin >> n >> m >> k;

    Sets sets;

    for (long long i = 0; i < k; i++) {
        string command;
        cin >> command;

        if (command == "ADD") {
            cin >> e >> s;
            sets.add(e, s);
        } else if (command == "DELETE") {
            cin >> e >> s;
            sets.del(e, s);
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
