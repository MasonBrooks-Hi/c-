#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> a[i][j];
    vector<int> rowOdd, colOdd;
    for (int i = 0; i < n; i++) {
        int s = 0;
        for (int j = 0; j < n; j++) s += a[i][j];
        if (s % 2) rowOdd.push_back(i);
    }
    for (int j = 0; j < n; j++) {
        int s = 0;
        for (int i = 0; i < n; i++) s += a[i][j];
        if (s % 2) colOdd.push_back(j);
    }
    if (rowOdd.empty() && colOdd.empty()) cout << "OK\n";
    else if (rowOdd.size() == 1 && colOdd.size() == 1)
        cout << rowOdd[0] + 1 << " " << colOdd[0] + 1 << "\n";
    else cout << "Corrupt\n";
    return 0;
}
