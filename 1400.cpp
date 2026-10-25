#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Stu {
    int score, grade;
};

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<Stu> v(n);
    for (int i = 0; i < n; i++) cin >> v[i].score >> v[i].grade;
    vector<int> order(n);
    for (int i = 0; i < n; i++) order[i] = i;
    sort(order.begin(), order.end(), [&](int x, int y) {
        if (v[x].score != v[y].score) return v[x].score > v[y].score;
        return v[x].grade < v[y].grade;
    });
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < i; j++)
            if (v[order[j]].grade < v[order[i]].grade) cnt++;
        cout << cnt << "\n";
    }
    return 0;
}
