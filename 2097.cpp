#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    int N;
    if (!(cin >> N)) return 0;
    map<string, string> mp;
    for (int i = 0; i < N; i++) {
        string id, rest;
        cin >> id;
        getline(cin, rest);
        mp[id] = id + rest;
    }
    int M;
    cin >> M;
    string q;
    while (M--) {
        cin >> q;
        if (mp.count(q)) cout << mp[q] << '\n';
        else cout << "No Answer!" << '\n';
    }
    return 0;
}
