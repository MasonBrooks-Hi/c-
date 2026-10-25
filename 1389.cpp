#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
    int N, K;
    if (!(cin >> N >> K)) return 0;
    vector<int> T(N), P(N);
    for (int i = 0; i < N; i++) cin >> T[i] >> P[i];
    vector<long long> free_time(K, 0);
    vector<int> served(K, 0);
    long long sum_wait = 0, max_wait = 0, last_complete = 0;
    for (int i = 0; i < N; i++) {
        int p = min(P[i], 60); // processing capped at 60
        int w = -1;
        bool anyFree = false;
        // check if any window free at arrival
        for (int j = 0; j < K; j++) {
            if (free_time[j] <= T[i]) { w = j; anyFree = true; break; }
        }
        if (anyFree) {
            // choose smallest index among free windows
            for (int j = 0; j < K; j++)
                if (free_time[j] <= T[i]) { w = j; break; }
        } else {
            // wait: choose min free_time, tie smallest index
            long long best = 1LL << 60;
            for (int j = 0; j < K; j++)
                if (free_time[j] < best) { best = free_time[j]; w = j; }
        }
        long long start = max((long long)T[i], free_time[w]);
        long long wait = start - T[i];
        sum_wait += wait;
        if (wait > max_wait) max_wait = wait;
        free_time[w] = start + p;
        if (free_time[w] > last_complete) last_complete = free_time[w];
        served[w]++;
    }
    double avg = (double)sum_wait / N;
    printf("%.1f %lld %lld\n", avg, max_wait, last_complete);
    for (int j = 0; j < K; j++) cout << served[j] << (j == K - 1 ? "" : " ");
    cout << "\n";
    return 0;
}
