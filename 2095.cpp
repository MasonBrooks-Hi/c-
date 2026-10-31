#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a;
    int x;
    while (cin >> x && x != 0) a.push_back(x);
    for (int i = (int)a.size() - 1; i >= 0; i--)
        cout << a[i] << (i == 0 ? '\n' : ' ');
    return 0;
}
