#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool    IsPalindrom(string word) {
    size_t  length = word.size();

    if (length == 0 || length == 1)
        return true;
    for (size_t i = 0; i < length / 2; ++i) {
        if (word[i] != word[length - 1 - i])
            return false;
    }
    return true;
}

vector <string> PalindromFilter(vector <string> words, int minLength) {
    vector <string> result;

    for (auto w : words) {
        if (w.size() >= minLength) {
            if (IsPalindrom(w))
                result.push_back(w);
        }
    }
    return result;
}
