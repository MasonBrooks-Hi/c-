#include <iostream>
#include <vector>
using namespace std;

struct Node { int val, left, right; };
vector<Node> a;
int target, cnt = 0, ans = -1;

void inorder(int idx) {
    if (idx == 0) return;
    inorder(a[idx].left);
    cnt++;
    if (a[idx].val == target && ans == -1) ans = cnt;
    inorder(a[idx].right);
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    cin >> target;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i].val >> a[i].left >> a[i].right;
    inorder(1);
    cout << ans << "\n";
    return 0;
}
