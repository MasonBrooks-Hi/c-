#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    const string d[10] = {"ling", "yi", "er", "san", "si",
                          "wu", "liu", "qi", "ba", "jiu"};
    string out;
    if (n < 10) {
        out = d[n];
    } else if (n == 10) {
        out = "shi";
    } else if (n % 10 == 0) {
        out = d[n / 10] + " shi";
    } else {
        out = d[n / 10] + " shi " + d[n % 10];
    }
    cout << out << '\n';
    return 0;
}
