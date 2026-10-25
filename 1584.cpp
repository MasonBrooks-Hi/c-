#include <iostream>
#include <set>
#include <queue>
using namespace std;

int main() {
    long long k, x;
    char comma;
    if (!(cin >> k >> comma >> x)) return 0;
    set<long long> s;
    queue<long long> q;
    s.insert(k);
    q.push(k);
    while (!q.empty()) {
        long long y = q.front();
        q.pop();
        long long a = 2 * y + 1, b = 3 * y + 1;
        if (a <= x && !s.count(a)) { s.insert(a); q.push(a); }
        if (b <= x && !s.count(b)) { s.insert(b); q.push(b); }
    }
    if (s.count(x)) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
