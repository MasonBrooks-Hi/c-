#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> a(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) cin >> a[i][j];
    int di[4] = {-1, 1, 0, 0};
    int dj[4] = {0, 0, -1, 1};
    int area = 0, peri = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            if (a[i][j] <= 50) {
                area++;
                bool bound = false;
                if (i == 0 || i == N - 1 || j == 0 || j == N - 1) bound = true;
                for (int d = 0; d < 4; d++) {
                    int ni = i + di[d], nj = j + dj[d];
                    if (ni < 0 || ni >= N || nj < 0 || nj >= N) continue;
                    if (a[ni][nj] > 50) bound = true;
                }
                if (bound) peri++;
            }
        }
    cout << area << " " << peri << endl;
    return 0;
}
