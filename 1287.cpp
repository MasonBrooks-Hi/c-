#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Stu { int id, score; };
int main() {
    int n, m;
    if (cin >> n >> m) {
        vector<Stu> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i].id >> v[i].score;
        sort(v.begin(), v.end(), [](const Stu& a, const Stu& b) {
            if (a.score != b.score) return a.score > b.score;
            return a.id < b.id;
        });
        int k = (m * 3) / 2;
        if (k > n) k = n;
        int line = v[k - 1].score;
        int cnt = 0;
        for (auto& s : v) if (s.score >= line) ++cnt;
        cout << line << " " << cnt << "\n";
        for (auto& s : v) if (s.score >= line) cout << s.id << " " << s.score << "\n";
    }
    return 0;
}
