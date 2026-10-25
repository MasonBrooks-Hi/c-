#include <iostream>
#include <vector>
using namespace std;
long long mergeCount(vector<int>& a, vector<int>& tmp, int l, int r) {
    if (l >= r) return 0;
    int mid = (l + r) / 2;
    long long cnt = mergeCount(a, tmp, l, mid) + mergeCount(a, tmp, mid + 1, r);
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) tmp[k++] = a[i++];
        else { tmp[k++] = a[j++]; cnt += (mid - i + 1); }
    }
    while (i <= mid) tmp[k++] = a[i++];
    while (j <= r) tmp[k++] = a[j++];
    for (int p = l; p <= r; ++p) a[p] = tmp[p];
    return cnt;
}
int main() {
    int n;
    if (cin >> n) {
        vector<int> a(n), tmp(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        cout << mergeCount(a, tmp, 0, n - 1) << endl;
    }
    return 0;
}
