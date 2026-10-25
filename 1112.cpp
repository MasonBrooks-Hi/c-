#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main() {
    string email;
    getline(cin, email);
    int N;
    cin >> N;
    bool any = false;
    for (int i = 0; i < N; i++) {
        string u, p, e;
        cin >> u >> p >> e;
        if (e == email) {
            any = true;
            for (char &c : p) {
                if (c >= 'a' && c <= 'z') c = c - 'a' + 'A';
                else if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
            }
            cout << u << " " << p << "\n";
        }
    }
    if (!any) cout << "empty\n";
    return 0;
}
