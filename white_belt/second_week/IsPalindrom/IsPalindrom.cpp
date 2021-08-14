#include <iostream>
#include <string>

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
