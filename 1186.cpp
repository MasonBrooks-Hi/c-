#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> M(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> M[i][j];
    for (int iter = 0; iter < n - 1; iter++) {
        cout << M[1][1] << endl;
        int sz = (int)M.size();
        for (int i = 0; i < sz; i++) {
            int mn = M[i][0];
            for (int j = 1; j < sz; j++) if (M[i][j] < mn) mn = M[i][j];
            for (int j = 0; j < sz; j++) M[i][j] -= mn;
        }
        for (int j = 0; j < sz; j++) {
            int mn = M[0][j];
            for (int i = 1; i < sz; i++) if (M[i][j] < mn) mn = M[i][j];
            for (int i = 0; i < sz; i++) M[i][j] -= mn;
        }
        int csz = sz - 1;
        vector<vector<int>> N(csz, vector<int>(csz));
        int ni = 0;
        for (int i = 0; i < sz; i++) {
            if (i == 1) continue;
            int nj = 0;
            for (int j = 0; j < sz; j++) {
                if (j == 1) continue;
                N[ni][nj++] = M[i][j];
            }
            ni++;
        }
        M = N;
    }
    return 0;
}
