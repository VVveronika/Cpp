#include <set>
#include <iostream>
#include <string>
#include <map>
using namespace std;

class Sets {
 private:
        map<int, multiset<long long>> sets;

 public:
        void add(int s, long long e) {
            sets[s].insert(e);
        }

        void del(int s, long long e) {
            sets[s].erase(sets[s].find(e));
        }

        void clear(int s) {
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
            bool element_finded = false;
            for (auto i : sets) {
                if (i.second.find(e) != i.second.end()) {
                    element_finded = true;
                    cout << i.first << " ";
                }
            }
            if (!element_finded) {
                cout << -1;
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
CLEAR 2
LISTSET 1
*/