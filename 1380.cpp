#include <iostream>
#include <string>
using namespace std;

struct Student {
    string id;
    string name;
};

int main() {
    int n;
    if (!(cin >> n)) return 0;
    Student st[105];
    for (int i = 0; i < n; i++) cin >> st[i].id >> st[i].name;
    for (int i = 0; i < n; i++)
        cout << "id:" << st[i].id << " name:" << st[i].name << "\n";
    return 0;
}
