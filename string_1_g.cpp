#include <string>
#include <vector>
#include <iostream>
#include <climits>

using namespace std;
const unsigned long long R = ULLONG_MAX;
const int P = 257;

bool is_prefix(vector<unsigned long long>& prefix_hash, vector<unsigned long long>& word_hash) {
    int prefix_size = prefix_hash.size();
    if (word_hash.size() <= prefix_size) {
        return false;
    }
    return prefix_hash[prefix_size - 1] == word_hash[prefix_size - 1];
}

int main() {
    int count_of_words;
    cin >> count_of_words;

    vector<vector<unsigned long long>> word_hash(count_of_words + 1);

    for (int i = 1; i <= count_of_words; i++) {
        string word;
        cin >> word;

        int word_size = word.size();
        // vector<unsigned long long> pows(word_size + 1);
        // pows[0] = 1;
        // vector<unsigned long long> hashes(word_size + 1);
        word_hash[i].resize(word_size + 1);

        for (int j = 1; j <= word_size; j++) {
            word_hash[i][j] = (word_hash[i][j - 1] * P % R + int(word[j - 1])% R) % R;
            // pows[i] = pows[i - 1] * P % R;
        }
    }

    int count_of_indexs;
    cin >> count_of_indexs;

    vector<int> indexes(count_of_indexs + 1);

    for (int i = 1; i <= count_of_indexs; i++) {
        cin >> indexes[i];
    }

    int left = 1;
    int right = 1;
    int best_left = 1;
    int best_right = 1;
    int len = 0;

    for (int i = 1; i < count_of_indexs; i++) {
        int cur_index = indexes[i];
        int next_index = indexes[i + 1];
        if (is_prefix(word_hash[cur_index], word_hash[next_index])) {
            right = i + 1;
        } else {
            if (right - left + 1 > len) {
                best_left = left;
                best_right = right;
                len = right - left + 1;
            }
            left = i + 1;
            right = i + 1;
        }
    }
    cout << best_left << ' ' << best_right;
    return 0;
}
