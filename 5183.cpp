#include <iostream>
using namespace std;

int main() {
    long long x, y;
    // 依次输入学生数量x和苹果数量y
    if (cin >> x >> y) {
        long long a = y / x; // 每个学生收到的苹果数
        long long b = y % x; // 剩下的苹果数
        
        // 按照题目要求的格式输出
        cout << "每个学生可以收到" << a << "个苹果，剩下" << b << "个苹果。" << endl;
    }
    return 0;
}
