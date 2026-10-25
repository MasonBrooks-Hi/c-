#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Stu { int id, total, ch; };
int main() {
    int n;
    if (cin >> n) {
        vector<Stu> v(n);
        for (int i = 0; i < n; ++i) {
            int a, b, c;
            cin >> a >> b >> c;
            v[i].id = i + 1;
            v[i].ch = a;
            v[i].total = a + b + c;
        }
        sort(v.begin(), v.end(), [](const Stu& a, const Stu& b) {
            if (a.total != b.total) return a.total > b.total;
            if (a.ch != b.ch) return a.ch > b.ch;
            return a.id < b.id;
        });
        for (int i = 0; i < 5 && i < n; ++i)
            cout << v[i].id << " " << v[i].total << "\n";
    }
    return 0;
}
