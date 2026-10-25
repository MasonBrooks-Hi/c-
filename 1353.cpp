#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdio>
using namespace std;

double eval() {
    string tok;
    cin >> tok;
    if (tok == "+") return eval() + eval();
    if (tok == "-") return eval() - eval();
    if (tok == "*") return eval() * eval();
    if (tok == "/") return eval() / eval();
    return stod(tok);
}

int main() {
    double v = eval();
    printf("%f\n", v);
    return 0;
}
