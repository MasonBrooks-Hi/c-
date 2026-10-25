#include <iostream>
#include <string>
using namespace std;
int main() {
    string w;
    cin >> w;
    int L = (int)w.size();
    if (L >= 2 && w.substr(L - 2) == "er") w = w.substr(0, L - 2);
    else if (L >= 2 && w.substr(L - 2) == "ly") w = w.substr(0, L - 2);
    else if (L >= 3 && w.substr(L - 3) == "ing") w = w.substr(0, L - 3);
    cout << w << "\n";
    return 0;
}
