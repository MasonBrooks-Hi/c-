#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    int a[100][100], b[100][100];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) cin >> a[i][j];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) cin >> b[i][j];
    int same = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] == b[i][j]) same++;
    double r = 100.0 * same / (m * n);
    printf("%.2lf\n", r);
    return 0;
}
