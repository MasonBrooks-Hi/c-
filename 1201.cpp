#include <iostream>
#include <vector>
using namespace std;

int main() {
    int row, col;
    cin >> row >> col;
    vector<vector<int>> a(row, vector<int>(col));
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++) cin >> a[i][j];
    int top = 0, bottom = row - 1, left = 0, right = col - 1;
    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++) cout << a[top][j] << endl;
        top++;
        for (int i = top; i <= bottom; i++) cout << a[i][right] << endl;
        right--;
        if (top <= bottom) {
            for (int j = right; j >= left; j--) cout << a[bottom][j] << endl;
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--) cout << a[i][left] << endl;
            left++;
        }
    }
    return 0;
}
