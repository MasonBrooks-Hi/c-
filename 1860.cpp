// 1860 链接a和b
// Concatenate two positive integers as strings.
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int main() {
    string a, b;
    if (!(cin >> a >> b)) return 0;
    printf("%s%s\n", a.c_str(), b.c_str());
    return 0;
}
