#include <iostream>
#include <string>
using namespace std;

int main() {
    string enc, plain, msg;
    cin >> enc >> plain >> msg;
    char map1[26]; // plaintext -> cipher
    char map2[26]; // cipher -> plaintext
    for (int i = 0; i < 26; i++) { map1[i] = 0; map2[i] = 0; }
    bool fail = false;
    for (int i = 0; i < (int)enc.size(); i++) {
        int x = plain[i] - 'A';
        int y = enc[i] - 'A';
        if (map1[x] != 0 && map1[x] != (char)('A' + y)) fail = true;
        if (map2[y] != 0 && map2[y] != (char)('A' + x)) fail = true;
        map1[x] = (char)('A' + y);
        map2[y] = (char)('A' + x);
    }
    for (int i = 0; i < 26; i++) if (map1[i] == 0) fail = true;
    if (fail) { cout << "Failed\n"; return 0; }
    for (char c : msg) cout << map2[c - 'A'];
    cout << endl;
    return 0;
}
