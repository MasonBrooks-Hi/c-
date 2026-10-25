#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string w;
        cin >> w;
        if (!w.empty() && w[0] >= 'a' && w[0] <= 'z') w[0] = w[0] - 'a' + 'A';
        for (size_t j = 1; j < w.size(); j++)
            if (w[j] >= 'A' && w[j] <= 'Z') w[j] = w[j] - 'A' + 'a';
        cout << w << "\n";
    }
    return 0;
}
