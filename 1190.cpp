#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool eq(const vector<string>& A, const vector<string>& B, int N) {
    for (int i = 0; i < N; i++)
        if (A[i] != B[i]) return false;
    return true;
}

string strip_spaces(const string& s) {
    string r;
    for (char ch : s) if (ch != ' ') r += ch;
    return r;
}

int main() {
    int N;
    cin >> N;
    vector<string> A(N), B(N);
    string line;
    getline(cin, line); // consume remainder of first line
    for (int i = 0; i < N; i++) {
        getline(cin, line);
        A[i] = strip_spaces(line);
    }
    for (int i = 0; i < N; i++) {
        getline(cin, line);
        B[i] = strip_spaces(line);
    }

    vector<string> R1(N, string(N, ' '));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) R1[i][j] = A[N - 1 - j][i];
    if (eq(R1, B, N)) { cout << 1 << endl; return 0; }

    vector<string> R2(N, string(N, ' '));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) R2[i][j] = A[j][N - 1 - i];
    if (eq(R2, B, N)) { cout << 2 << endl; return 0; }

    vector<string> R3(N, string(N, ' '));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) R3[i][j] = A[N - 1 - i][N - 1 - j];
    if (eq(R3, B, N)) { cout << 3 << endl; return 0; }

    if (eq(A, B, N)) { cout << 4 << endl; return 0; }
    cout << 5 << endl;
    return 0;
}
