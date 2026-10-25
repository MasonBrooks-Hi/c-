#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<int> ans(n + 1);
    queue<int> q;
    for (int i = 1; i <= n; i++) q.push(i);
    for (int i = 1; i <= n; i++) {
        int p = q.front();
        q.pop();
        ans[p] = i;
        // 拿出后把紧接着的两张依次放到末尾（不够则有多少放多少）
        for (int t = 0; t < 2 && !q.empty(); t++) {
            q.push(q.front());
            q.pop();
        }
    }
    // 快速输出
    string out;
    out.reserve((size_t)n * 7);
    for (int i = 1; i <= n; i++) {
        if (i > 1) out.push_back(' ');
        out += to_string(ans[i]);
    }
    out.push_back('\n');
    cout << out;
    return 0;
}
