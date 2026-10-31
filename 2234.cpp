#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) if (n % i == 0) return false;
    return true;
}

vector<int> ans;
int N;

void dfs(long long cur, int len) {
    if (len == N) { ans.push_back((int)cur); return; }
    for (int d : {1, 3, 7, 9}) {
        long long nxt = cur * 10 + d;
        if (isPrime((int)nxt)) dfs(nxt, len + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    if (!(cin >> N)) return 0;
    for (int seed : {2, 3, 5, 7}) {
        if (isPrime(seed)) dfs(seed, 1);
    }
    for (int v : ans) cout << v << "\n";
    return 0;
}
