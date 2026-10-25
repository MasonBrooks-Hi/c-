#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int R, C;
    cin >> R >> C;
    string s;
    while (cin.peek() == ' ' || cin.peek() == '\t' || cin.peek() == '\n') cin.get();
    getline(cin, s);

    string bits;
    for (char ch : s) {
        int v = (ch == ' ') ? 0 : (ch - 'A' + 1);
        for (int b = 4; b >= 0; b--)
            bits += ((v >> b) & 1) ? '1' : '0';
    }
    int total = R * C;
    while ((int)bits.size() < total) bits += '0';

    vector<pair<int, int>> order;
    int top = 0, bottom = R - 1, left = 0, right = C - 1;
    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++) order.push_back({top, j});
        top++;
        for (int i = top; i <= bottom; i++) order.push_back({i, right});
        right--;
        if (top <= bottom) {
            for (int j = right; j >= left; j--) order.push_back({bottom, j});
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--) order.push_back({i, left});
            left++;
        }
    }
    vector<vector<char>> M(R, vector<char>(C, '0'));
    for (int k = 0; k < total; k++) M[order[k].first][order[k].second] = bits[k];

    string out;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++) out += M[i][j];
    cout << out << endl;
    return 0;
}
