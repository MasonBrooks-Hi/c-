#include <iostream>
#include <string>
using namespace std;
int main() {
    int M;
    if (cin >> M) {
        int d = M % 7;
        string names[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
        cout << names[d] << endl;
    }
    return 0;
}
