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
    
    long long ans = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            for(int k = i + 1; k < n; ++k) {
                for(int l = j + 1; l < n; ++l) {
                    if(not (min(a[i][j], a[k][l]) > max(a[i][l], a[k][j]) or max(a[i][j], a[k][l]) < min(a[i][l], a[k][j]))) {
                        ++ans;
                    }
                }
            }
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}
