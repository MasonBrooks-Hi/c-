#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    double confirmed, deaths;
    cin >> confirmed >> deaths;
    printf("%.3lf%%\n", deaths / confirmed * 100.0);
    return 0;
}
