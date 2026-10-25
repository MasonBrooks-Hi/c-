#include <iostream>
#include <vector>
using namespace std;

vector<long long> tmp;
long long cnt = 0;

void merge(vector<long long>& a, int l, int r) {
    if (l >= r) return;
    int mid = (l + r) / 2;
    merge(a, l, mid);
    merge(a, mid + 1, r);
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) tmp[k++] = a[i++];
        else { tmp[k++] = a[j++]; cnt += (mid - i + 1); }
    }
    while (i <= mid) tmp[k++] = a[i++];
    while (j <= r) tmp[k++] = a[j++];
    for (int t = l; t <= r; t++) a[t] = tmp[t];
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    tmp.resize(n);
    cnt = 0;
    merge(a, 0, n - 1);
    cout << cnt << "\n";
    return 0;
}
