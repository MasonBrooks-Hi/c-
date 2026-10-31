#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
    int score, w, id;
};

bool cmp(const Node& a, const Node& b) {
    if (a.score != b.score) return a.score > b.score;
    return a.id < b.id;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, R, Q;
    if (!(cin >> N >> R >> Q)) return 0;
    int tot = 2 * N;
    vector<Node> a(tot);
    for (int i = 0; i < tot; i++) { cin >> a[i].score; a[i].id = i + 1; }
    for (int i = 0; i < tot; i++) cin >> a[i].w;
    sort(a.begin(), a.end(), cmp);
    vector<Node> win(N), lose(N);
    while (R--) {
        int cw = 0, cl = 0;
        for (int i = 0; i < tot; i += 2) {
            if (a[i].w > a[i + 1].w) {
                a[i].score++;
                win[cw++] = a[i];
                lose[cl++] = a[i + 1];
            } else {
                a[i + 1].score++;
                win[cw++] = a[i + 1];
                lose[cl++] = a[i];
            }
        }
        int i = 0, j = 0, k = 0;
        while (i < cw && j < cl) {
            if (cmp(win[i], lose[j])) a[k++] = win[i++];
            else a[k++] = lose[j++];
        }
        while (i < cw) a[k++] = win[i++];
        while (j < cl) a[k++] = lose[j++];
    }
    sort(a.begin(), a.end(), cmp);
    cout << a[Q - 1].id << "\n";
    return 0;
}
