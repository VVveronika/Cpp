#include <iostream>
#include <map>
#include <vector>

using namespace std;

int guess(int i) {
    cout << i << endl;

    int answer = 0;
    cin >> answer;
    return answer;
}

void answer_out(vector<int> answer) {
    cout << "! ";
    for (int i : answer) {
        cout << i << ' ';
    }
    cout << endl;
}

struct Pair_data {
    int index_hero;
    int index_of_pair = 0;
};

int make_turn(int last, vector<multimap<int, Pair_data> ::iterator>& pair_iterators, multimap<int, Pair_data>& heroes) {
    int answer = 0;
    if (last != 0) {
        auto& pair = pair_iterators[last]->second;
        answer = pair.index_of_pair;
        if (answer != 0 && pair_iterators[answer]->second.index_hero == 0) {
            answer = 0;
        }
        pair.index_hero = 0;
    }
    if (answer == 0) {
        for (auto i = heroes.rbegin(); i != heroes.rend(); i++) {
            auto hero = i->second;
            if (hero.index_hero == 0) {
                continue;
            }
            if (hero.index_of_pair != 0) {
                answer = hero.index_hero;
                break;
            }
            if (answer == 0) {
                answer = hero.index_hero;
            }
        }

    }
    if (answer != 0) {
        pair_iterators[answer]->second.index_hero = 0;
    }
    return answer;
}


int main() {
    int n, m;
    cin >> n >> m;

    multimap<int, Pair_data> heroes;
    vector<multimap<int, Pair_data> ::iterator> pair_iterators(n * 2 + 1);

    for (int i = 1; i <= 2 * n; i++) {
        int force;
        cin >> force;
        Pair_data cur_element;
        cur_element.index_hero = i;
        auto it = heroes.insert(make_pair(force, cur_element));
        pair_iterators[i] = it;
    }
    auto z = pair_iterators[5]->second;

    for (int i = 0; i < m; i++) {
        int p1, p2;
        cin >> p1 >> p2;
        pair_iterators[p1]->second.index_of_pair = p2;
        pair_iterators[p2]->second.index_of_pair = p1;
    }

    int order;
    cin >> order;
    int last = 0;

    if (order == 2) {
        cin >> last;
    }

    while (true) {
        last = make_turn(last, pair_iterators, heroes);
        if (last == 0) {
            break;
        }
        last = guess(last);
    }
    return 0;
}
