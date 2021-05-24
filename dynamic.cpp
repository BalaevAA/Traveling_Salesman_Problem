#include <bits/stdc++.h>
#include<chrono>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n = 4;
    int sizeI = 4, sizeJ = 4;
    vector<vector<int> > a = {  {999, 1,  4,  6 },
                                { 1, 999, 5,  2 },
                                { 4,  5, 999, 3 },
                                { 6,  2,  3, 999}   };

    vector<vector<int> > d((1 << n), vector<int>(n, 999));
    d[0][0] = 0;

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (d[mask][i] == 999)
                continue;
            for (int j = 0; j < n; j++)
                if (!(mask & (1 << j))) {
                    d[mask ^ (1 << j)][j] = std::min(d[mask | (1 << j)][j], d[mask][i] + a[i][j]);
                }
        }
    }

    cout << d[(1 << n) - 1][0] << "\n";
    return 0;
}
