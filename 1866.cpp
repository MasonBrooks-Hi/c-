// 1866 词组缩写
// Uppercase first letter of each word.
#include <cstdio>
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main() {
    string line;
    getline(cin, line);
    string res;
    bool newWord = true;
    for (char c : line) {
        if (isspace((unsigned char)c)) newWord = true;
        else {
            if (newWord) res += (char)toupper((unsigned char)c);
            newWord = false;
        }
    }
    printf("%s\n", res.c_str());
    return 0;
}
