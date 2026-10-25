// 1740 寻找Nemo
// Unit-square grid BFS with 0/1 weights: crossing a wall edge is blocked unless a door
// covers that unit edge (cost 1); free movement costs 0.
// Walls/doors have integer endpoints in [1,199]; unit edges align with the grid.
#include <cstdio>
#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int M, N;
    while (cin >> M >> N) {
        if (M == -1 && N == -1) break;
        vector<vector<int>> walls(M, vector<int>(4));
        for (auto &w : walls) cin >> w[0] >> w[1] >> w[2] >> w[3];
        vector<vector<int>> doors(N, vector<int>(3));
        for (auto &d : doors) cin >> d[0] >> d[1] >> d[2];
        double f1, f2;
        cin >> f1 >> f2;
        int wallMaxX = 1, wallMaxY = 1;
        for (auto &w : walls) {
            if (w[2] == 0) wallMaxX = max(wallMaxX, w[0] + w[3]); else wallMaxY = max(wallMaxY, w[1] + w[3]);
            wallMaxX = max(wallMaxX, w[0]); wallMaxY = max(wallMaxY, w[1]);
        }
        for (auto &d : doors) {
            if (d[2] == 0) wallMaxX = max(wallMaxX, d[0] + 1); else wallMaxY = max(wallMaxY, d[1] + 1);
            wallMaxX = max(wallMaxX, d[0]); wallMaxY = max(wallMaxY, d[1]);
        }
        int tx = (int)floor(f1), ty = (int)floor(f2);
        if (tx < 0) tx = 0;
        if (ty < 0) ty = 0;
        // Nemo beyond every wall (east/north of the wall bounding box): both he and Marlin
        // (at (0,0)) are in the unbounded exterior region -> 0 doors.
        if (tx > wallMaxX || ty > wallMaxY) {
            printf("0\n");
            continue;
        }
        int maxX = max(wallMaxX, tx), maxY = max(wallMaxY, ty);
        // squares (i,j): x in [i,i+1], y in [j,j+1], i in [0,maxX], j in [0,maxY]
        int SX = maxX + 1, SY = maxY + 1;
        // vertical edge at x=i separating squares (i-1,j)-(i,j): covered for y in [j,j+1]
        vector<vector<char>> blockV(SX + 2, vector<char>(SY + 2, 0));
        vector<vector<char>> doorV(SX + 2, vector<char>(SY + 2, 0));
        vector<vector<char>> blockH(SX + 2, vector<char>(SY + 2, 0));
        vector<vector<char>> doorH(SX + 2, vector<char>(SY + 2, 0));
        for (auto &w : walls) {
            int x = w[0], y = w[1], d = w[2], t = w[3];
            if (d == 0) { // horizontal wall (x,y)-(x+t,y)
                for (int i = x; i < x + t; i++)
                    if (i >= 0 && i <= SX && y >= 0 && y <= SY) blockH[i][y] = 1;
            } else {      // vertical wall (x,y)-(x,y+t)
                for (int j = y; j < y + t; j++)
                    if (x >= 0 && x <= SX && j >= 0 && j <= SY) blockV[x][j] = 1;
            }
        }
        for (auto &d : doors) {
            int x = d[0], y = d[1], dd = d[2];
            if (dd == 0) { if (x >= 0 && x <= SX && y >= 0 && y <= SY) doorH[x][y] = 1; }
            else { if (x >= 0 && x <= SX && y >= 0 && y <= SY) doorV[x][y] = 1; }
        }
        // 0-1 BFS from square (0,0)
        vector<vector<int>> dist(SX + 1, vector<int>(SY + 1, -1));
        deque<pair<int, int>> dq;
        dist[0][0] = 0;
        dq.push_front({0, 0});
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        while (!dq.empty()) {
            auto [x, y] = dq.front(); dq.pop_front();
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir], ny = y + dy[dir];
                if (nx < 0 || nx > maxX || ny < 0 || ny > maxY) continue;
                int cost = 0;
                if (dir == 0) { // cross vertical edge x+1, y interval [y,y+1]
                    if (blockV[x + 1][y]) {
                        if (!doorV[x + 1][y]) continue;
                        cost = 1;
                    }
                } else if (dir == 1) { // cross vertical edge x
                    if (blockV[x][y]) {
                        if (!doorV[x][y]) continue;
                        cost = 1;
                    }
                } else if (dir == 2) { // cross horizontal edge y+1
                    if (blockH[x][y + 1]) {
                        if (!doorH[x][y + 1]) continue;
                        cost = 1;
                    }
                } else { // cross horizontal edge y
                    if (blockH[x][y]) {
                        if (!doorH[x][y]) continue;
                        cost = 1;
                    }
                }
                if (dist[nx][ny] == -1 || dist[nx][ny] > dist[x][y] + cost) {
                    dist[nx][ny] = dist[x][y] + cost;
                    if (cost == 0) dq.push_front({nx, ny});
                    else dq.push_back({nx, ny});
                }
            }
        }
        printf("%d\n", dist[tx][ty]);
    }
    return 0;
}
