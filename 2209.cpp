#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string key, cipher;
    if (!(cin >> key >> cipher)) return 0;
    int kl = key.length();
    string plain;
    int j = 0;
    for (char c : cipher) {
        char kc = key[j % kl];
        int kbase = ('a' <= kc && kc <= 'z') ? 'a' : 'A';
        int cbase = ('a' <= c && c <= 'z') ? 'a' : 'A';
        int kv = kc - kbase;
        int cv = c - cbase;
        int pv = (cv - kv + 26) % 26;
        plain.push_back((char)(cbase + pv));
        j++;
    }
    cout << plain << "\n";
    return 0;
}
