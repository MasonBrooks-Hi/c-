#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int R, C;
    cin >> R >> C;
    vector<string> g(R);
    for (int i = 0; i < R; i++) cin >> g[i];
    int di[4] = {-1, 1, 0, 0};
    int dj[4] = {0, 0, -1, 1};
    int cnt = 0;
    int stk[10000];
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++) {
            if (g[i][j] == '#') {
                cnt++;
                int top = 0;
                stk[top++] = i * C + j;
                g[i][j] = '.';
                while (top > 0) {
                    int v = stk[--top];
                    int ci = v / C, cj = v % C;
                    for (int d = 0; d < 4; d++) {
                        int ni = ci + di[d], nj = cj + dj[d];
                        if (ni >= 0 && ni < R && nj >= 0 && nj < C && g[ni][nj] == '#') {
                            g[ni][nj] = '.';
                            stk[top++] = ni * C + nj;
                        }
                    }
                }
            }
        }
    cout << cnt << endl;
    return 0;
}
