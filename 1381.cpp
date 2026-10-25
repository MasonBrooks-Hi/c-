#include <iostream>
#include <string>
using namespace std;

struct stu {
    string id;
    string name;
};

int main() {
    stu s;
    if (!(cin >> s.id >> s.name)) return 0;
    cout << s.id << "," << s.name << "\n";
    return 0;
}
