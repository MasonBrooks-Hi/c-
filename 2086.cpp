#include <iostream>
using namespace std;

int a[105][105];

int main() {
    int N;
    if (!(cin >> N)) return 0;
    int x = 0, y = N - 1, val = 1;
    int dx[4] = {1, 0, -1, 0};   // down, left, up, right
    int dy[4] = {0, -1, 0, 1};
    int dir = 0;
    while (val <= N * N) {
        a[x][y] = val++;
        int nx = x + dx[dir], ny = y + dy[dir];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N || a[nx][ny] != 0) {
            dir = (dir + 1) % 4;
            nx = x + dx[dir];
            ny = y + dy[dir];
        }
        x = nx;
        y = ny;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j) cout << ' ';
            cout << a[i][j];
        }
        cout << '\n';
    }
    return 0;
}
