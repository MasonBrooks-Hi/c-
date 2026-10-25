#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long a, b, c;
    if (!(cin >> a >> b >> c)) return 0;
    if (!(a + b > c && a + c > b && b + c > a)) {
        cout << "not a triangle\n";
    } else {
        long long arr[3] = {a, b, c};
        sort(arr, arr + 3);
        if (arr[0] * arr[0] + arr[1] * arr[1] == arr[2] * arr[2])
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}
