#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    string days[8] = {"", "Monday", "Tuesday", "Wednesday", "Thursday",
                      "Friday", "Saturday", "Sunday"};
    cout << days[n] << "\n";
    return 0;
}
