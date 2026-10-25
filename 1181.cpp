#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    int maxs = -1;
    string name, best;
    for (int i = 0; i < n; i++) {
        int s;
        cin >> s >> name;
        if (s > maxs) {
            maxs = s;
            best = name;
        }
    }
    cout << best << endl;
    return 0;
}
