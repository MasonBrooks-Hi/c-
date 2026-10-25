// 1889 二分查找
// Binary search for x among 10 sorted integers; output 1-based position or -1.
#include <cstdio>
int main() {
    int x;
    if (scanf("%d", &x) != 1) return 0;
    int a[10];
    for (int i = 0; i < 10; i++) scanf("%d", &a[i]);
    int pos = -1;
    int lo = 0, hi = 9;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (a[mid] == x) { pos = mid + 1; break; }
        if (a[mid] < x) lo = mid + 1;
        else hi = mid - 1;
    }
    printf("%d\n", pos);
    return 0;
}
