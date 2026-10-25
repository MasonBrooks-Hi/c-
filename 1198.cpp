#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int c;
    cin >> c;
    string s;
    cin >> s;
    int len = (int)s.size();
    int rows = (len + c - 1) / c;
    vector<string> M(rows, string(c, ' '));
    int p = 0;
    for (int i = 0; i < rows; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < c; j++) M[i][j] = s[p++];
        } else {
            for (int j = c - 1; j >= 0; j--) M[i][j] = s[p++];
        }
    }
    string out;
    for (int j = 0; j < c; j++)
        for (int i = 0; i < rows; i++) out += M[i][j];
    cout << out << endl;
    return 0;
}
