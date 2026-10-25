// 1737 小游戏
// BFS over cells of the board (plus a ring of cells just outside the board).
// Moving along one row/column segment (no card strictly in between) costs 1 segment.
// Cards block the path; the target card B may be entered (endpoint), other cards may not be touched.
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int W, H;
vector<string> g;

int solve(int ax, int ay, int bx, int by) {
    if (ax < 1 || ax > W || ay < 1 || ay > H || bx < 1 || bx > W || by < 1 || by > H)
        return -1; // defensive: queries should always be on the board
    if (ax == bx && ay == by) return 0;
    int M = W + 2;      // cells x in [0, W+1]  -> indices 0..M-1
    int N = H + 2;      // cells y in [0, H+1]
    auto cardAt = [&](int x, int y) -> bool {
        if (x < 1 || x > W || y < 1 || y > H) return false;
        if (x == bx && y == by) return false; // target is passable (endpoint)
        return g[y - 1][x - 1] == 'X';
    };
    // next card in each direction (per row / per column)
    static vector<vector<int>> ncR, ncL, ncD, ncU;
    ncR.assign(N, vector<int>(M));
    ncL.assign(N, vector<int>(M));
    ncD.assign(M, vector<int>(N));
    ncU.assign(M, vector<int>(N));
    for (int y = 0; y < N; y++) {
        ncR[y][M - 1] = M; // sentinel: none
        for (int x = M - 2; x >= 0; x--) ncR[y][x] = cardAt(x + 1, y) ? x + 1 : ncR[y][x + 1];
        ncL[y][0] = -1;
        for (int x = 1; x < M; x++) ncL[y][x] = cardAt(x - 1, y) ? x - 1 : ncL[y][x - 1];
    }
    for (int x = 0; x < M; x++) {
        ncD[x][N - 1] = N;
        for (int y = N - 2; y >= 0; y--) ncD[x][y] = cardAt(x, y + 1) ? y + 1 : ncD[x][y + 1];
        ncU[x][0] = -1;
        for (int y = 1; y < N; y++) ncU[x][y] = cardAt(x, y - 1) ? y - 1 : ncU[x][y - 1];
    }
    // linked lists of unvisited cells (per row for horizontal, per column for vertical)
    static vector<vector<int>> fr, fl, fu, fd;
    fr.assign(N, vector<int>(M + 1));
    fl.assign(N, vector<int>(M + 2));
    fd.assign(M, vector<int>(N + 1));
    fu.assign(M, vector<int>(N + 2));
    for (int y = 0; y < N; y++) {
        for (int x = 0; x <= M; x++) fr[y][x] = x;
        fl[y][0] = -1;
        for (int x = 0; x < M; x++) fl[y][x + 1] = x;
        fl[y][M + 1] = M - 1;
    }
    for (int x = 0; x < M; x++) {
        for (int y = 0; y <= N; y++) fd[x][y] = y;
        fu[x][0] = -1;
        for (int y = 0; y < N; y++) fu[x][y + 1] = y;
        fu[x][N + 1] = N - 1;
    }
    auto findR = [&](int y, int x) {
        while (fr[y][x] != x) { fr[y][x] = fr[y][fr[y][x]]; x = fr[y][x]; }
        return x;
    };
    auto findL = [&](int y, int x) {
        while (fl[y][x + 1] != x) { fl[y][x + 1] = fl[y][fl[y][x + 1] + 1]; x = fl[y][x + 1]; }
        return x;
    };
    auto findD = [&](int x, int y) {
        while (fd[x][y] != y) { fd[x][y] = fd[x][fd[x][y]]; y = fd[x][y]; }
        return y;
    };
    auto findU = [&](int x, int y) {
        while (fu[x][y + 1] != y) { fu[x][y + 1] = fu[x][fu[x][y + 1] + 1]; y = fu[x][y + 1]; }
        return y;
    };
    static vector<vector<int>> dist;
    dist.assign(N, vector<int>(M, -1));
    queue<pair<int, int>> q;
    dist[ay][ax] = 0;
    q.push({ax, ay});
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        int d = dist[y][x];
        // right
        int end = min(ncR[y][x] - 1, M - 1);
        int p = (x + 1 <= M) ? findR(y, x + 1) : M;
        while (p <= end) {
            if (dist[y][p] == -1) { dist[y][p] = d + 1; q.push({p, y}); }
            fr[y][p] = p + 1;
            p = findR(y, p + 1);
        }
        // left
        end = max(ncL[y][x] + 1, 0);
        p = (x - 1 >= 0) ? findL(y, x - 1) : -1;
        while (p >= end) {
            if (dist[y][p] == -1) { dist[y][p] = d + 1; q.push({p, y}); }
            fl[y][p + 1] = p - 1;
            p = findL(y, p - 1);
        }
        // down
        end = min(ncD[x][y] - 1, N - 1);
        p = (y + 1 <= N) ? findD(x, y + 1) : N;
        while (p <= end) {
            if (dist[p][x] == -1) { dist[p][x] = d + 1; q.push({x, p}); }
            fd[x][p] = p + 1;
            p = findD(x, p + 1);
        }
        // up
        end = max(ncU[x][y] + 1, 0);
        p = (y - 1 >= 0) ? findU(x, y - 1) : -1;
        while (p >= end) {
            if (dist[p][x] == -1) { dist[p][x] = d + 1; q.push({x, p}); }
            fu[x][p + 1] = p - 1;
            p = findU(x, p - 1);
        }
    }
    return dist[by][bx];
}

int main() {
    string line;
    int boardNum = 0;
    while (cin >> W >> H) {
        if (W == 0 && H == 0) break;
        getline(cin, line); // consume end of current line
        g.assign(H, string());
        for (int i = 0; i < H; i++) {
            getline(cin, line);
            if ((int)line.size() < W) line += string(W - line.size(), ' ');
            g[i] = line.substr(0, W);
        }
        boardNum++;
        printf("Board #%d:\n", boardNum);
        int pairNum = 0;
        while (true) {
            int x1, y1, x2, y2;
            if (!(cin >> x1 >> y1 >> x2 >> y2)) return 0;
            if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0) break;
            pairNum++;
            int d = solve(x1, y1, x2, y2);
            if (d < 0) printf("Pair %d: impossible.\n", pairNum);
            else printf("Pair %d: %d segments.\n", pairNum, d);
        }
        printf("\n");
    }
    return 0;
}
