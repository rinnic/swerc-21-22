#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>


using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    
    vector<vector<int>> a_sorted(n, vector<int>(n));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            a_sorted[i][j] = j;
        }
    }
    for(int i = 0; i < n; ++i) {
        sort(a_sorted[i].begin(), a_sorted[i].end(), [&](int x, int y) { return a[i][x] < a[i][y]; });
    }
    
    unsigned char i_used[n], j_used[n];
    
    long long ans = (long long)(n) * n * (n - 1) * (n - 1) / 4;
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            memset(i_used, 0, n);
            memset(j_used, 0, n);
            int pi = 0, pj = 0;
            int i_unpaired = 0, j_unpaired = 0;
            for(int k = 0; k < 2 * n; ++k) {
                if(pj == n or (pi < n and a[i][a_sorted[i][pi]] < a[j][a_sorted[j][pj]])) {
                    if(not j_used[a_sorted[i][pi]]) {
                        ans -= j_unpaired;
                        ++i_unpaired;
                        i_used[a_sorted[i][pi]] = 1;
                    } else {
                        --j_unpaired;
                    }
                    ++pi;
                } else {
                    if(not i_used[a_sorted[j][pj]]) {
                        ans -= i_unpaired;
                        ++j_unpaired;
                        j_used[a_sorted[j][pj]] = 1;
                    } else {
                        --i_unpaired;
                    }
                    ++pj;
                }
            }
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}
