#include <iostream>
using namespace std;

int main() {
    int k;
    cin >> k;
    long long total = 0;
    int day = 0, block = 1;
    while (day < k) {
        int take = (block <= k - day) ? block : (k - day);
        total += (long long)take * block;
        day += take;
        block++;
    }
    cout << total << endl;
    return 0;
}
