#include <iostream>
#include <vector>
using namespace std;

int main() {
    int row, col;
    cin >> row >> col;
    vector<vector<int>> a(row, vector<int>(col));
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++) cin >> a[i][j];
    for (int s = 0; s <= row + col - 2; s++) {
        int istart = max(0, s - col + 1);
        int iend = min(row - 1, s);
        for (int i = istart; i <= iend; i++)
            cout << a[i][s - i] << endl;
    }
    return 0;
}
