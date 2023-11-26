#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<string, string> library;

    for (int i = 0; i < n; i++) {
        string synonym_1, synonym_2;
        cin >> synonym_1 >> synonym_2;
        library[synonym_1] = synonym_2;
        library[synonym_2] = synonym_1;
    }

    string word;
    cin >> word;

    cout << library.find(word)->second;
}
