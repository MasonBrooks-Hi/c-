#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    if (!(cin >> n)) return 0;
    vector<string> flu;
    for (int i = 0; i < n; i++) {
        string name;
        double temp;
        int cough;
        cin >> name >> temp >> cough;
        if (temp >= 37.5 && cough == 1) flu.push_back(name);
    }
    for (auto& s : flu) cout << s << "\n";
    cout << (int)flu.size() << "\n";
    return 0;
}
