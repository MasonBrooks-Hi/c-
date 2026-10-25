#include <iostream>
#include <string>
using namespace std;

int main() {
    double th;
    cin >> th;
    string s1, s2;
    cin >> s1 >> s2;
    int same = 0;
    for (int i = 0; i < (int)s1.size(); i++) if (s1[i] == s2[i]) same++;
    double r = (double)same / s1.size();
    if (r >= th) cout << "yes\n";
    else cout << "no\n";
    return 0;
}
