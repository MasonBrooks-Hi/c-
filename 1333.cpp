#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct Pat { string id; int age; int ord; };
int main() {
    int n;
    if (cin >> n) {
        vector<Pat> v(n);
        for (int i = 0; i < n; ++i) { cin >> v[i].id >> v[i].age; v[i].ord = i; }
        sort(v.begin(), v.end(), [](const Pat& a, const Pat& b) {
            bool aOld = a.age >= 60, bOld = b.age >= 60;
            if (aOld && !bOld) return true;
            if (!aOld && bOld) return false;
            if (aOld && bOld) {
                if (a.age != b.age) return a.age > b.age;
                return a.ord < b.ord;
            }
            return a.ord < b.ord;
        });
        for (auto& p : v) cout << p.id << "\n";
    }
    return 0;
}
