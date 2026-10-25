#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    string line;
    cin >> line; // 整行无空格，可用 >> 读入
    // 按 '!' 分割，每个音节视为八进制数转十进制，再拼接
    string result;
    size_t start = 0;
    while (start <= line.size()) {
        size_t pos = line.find('!', start);
        string tok = (pos == string::npos) ? line.substr(start)
                                           : line.substr(start, pos - start);
        if (!tok.empty()) {
            long long val = 0;
            for (char c : tok) val = val * 8 + (c - '0');
            result += to_string(val);
        }
        if (pos == string::npos) break;
        start = pos + 1;
    }
    cout << result << '\n';
    return 0;
}
