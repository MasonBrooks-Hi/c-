#include <iostream>
using namespace std;
int main() {
    for (int i = 2; i <= 100; i++) {
        int s = 0;
        for (int j = 1; j < i; j++)
            if (i % j == 0) s += j;
        if (s == i) cout << i << "\n";
    }
    return 0;
}
