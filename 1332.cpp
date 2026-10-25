#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;
int main() {
    int n;
    if (cin >> n) {
        vector<pair<double, int>> male, female;
        string sex;
        double h;
        for (int i = 0; i < n; ++i) {
            cin >> sex >> h;
            if (sex == "male") male.push_back({h, 0});
            else female.push_back({h, 0});
        }
        sort(male.begin(), male.end());
        sort(female.begin(), female.end(), greater<pair<double, int>>());
        cout << fixed << setprecision(2);
        bool first = true;
        for (auto& p : male) { if (!first) cout << " "; cout << p.first; first = false; }
        for (auto& p : female) { if (!first) cout << " "; cout << p.first; first = false; }
        cout << endl;
    }
    return 0;
}
