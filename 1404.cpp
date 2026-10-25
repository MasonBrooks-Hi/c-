#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
    int r;
    if (!(cin >> r)) return 0;
    int totalA = 0, totalB = 0;
    while (true) {
        string line;
        if (!getline(cin, line)) break;
        // skip empty lines
        size_t p = line.find_first_not_of(" \r\n\t");
        if (p == string::npos) continue;
        // check for -1 (abandon)
        istringstream ts(line);
        int first;
        if (ts >> first) {
            if (first == -1) break;
        }
        // line is team A's 8 distances
        vector<int> A(8), B(8);
        A[0] = first;
        for (int i = 1; i < 8; i++) ts >> A[i];
        // next line: team B
        string line2;
        if (!getline(cin, line2)) break;
        istringstream ts2(line2);
        for (int i = 0; i < 8; i++) ts2 >> B[i];

        int amin = A[0], bmin = B[0];
        for (int i = 1; i < 8; i++) { if (A[i] < amin) amin = A[i]; if (B[i] < bmin) bmin = B[i]; }
        int scoreA = 0, scoreB = 0;
        if (amin < bmin) {
            for (int i = 0; i < 8; i++)
                if (A[i] <= r && A[i] < bmin) scoreA++;
        } else if (bmin < amin) {
            for (int i = 0; i < 8; i++)
                if (B[i] <= r && B[i] < amin) scoreB++;
        }
        cout << scoreA << ":" << scoreB << "\n";
        totalA += scoreA; totalB += scoreB;
    }
    cout << totalA << ":" << totalB << "\n";
    return 0;
}
