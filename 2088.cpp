#include <iostream>
using namespace std;

// win[a][b] = true if gesture a beats gesture b
bool win[5][5] = {
    {0,0,1,1,0}, // 0 剪刀 beats 布(2), 蜥蜴人(3)
    {1,0,0,1,0}, // 1 石头 beats 剪刀(0), 蜥蜴人(3)
    {0,1,0,0,1}, // 2 布   beats 石头(1), 斯波克(4)
    {0,0,1,0,1}, // 3 蜥蜴人 beats 布(2), 斯波克(4)
    {1,1,0,0,0}  // 4 斯波克 beats 剪刀(0), 石头(1)
};

int main() {
    int N, NA, NB;
    if (!(cin >> N >> NA >> NB)) return 0;
    int A[NA], B[NB];
    for (int i = 0; i < NA; i++) cin >> A[i];
    for (int i = 0; i < NB; i++) cin >> B[i];
    int sa = 0, sb = 0;
    for (int r = 0; r < N; r++) {
        int a = A[r % NA], b = B[r % NB];
        if (win[a][b]) sa++;
        else if (win[b][a]) sb++;
    }
    cout << sa << ' ' << sb << '\n';
    return 0;
}
