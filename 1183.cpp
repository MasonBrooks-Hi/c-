#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    string best;
    long long bestmoney = -1, total = 0;
    for (int i = 0; i < n; i++) {
        string name;
        int avg, cls, papers;
        char cad, west;
        cin >> name >> avg >> cls >> cad >> west >> papers;
        long long money = 0;
        if (avg > 80 && papers >= 1) money += 8000;
        if (avg > 85 && cls > 80) money += 4000;
        if (avg > 90) money += 2000;
        if (avg > 85 && west == 'Y') money += 1000;
        if (cad == 'Y' && cls > 80) money += 850;
        total += money;
        if (money > bestmoney) {
            bestmoney = money;
            best = name;
        }
    }
    cout << best << endl << bestmoney << endl << total << endl;
    return 0;
}
