#include <bits/stdc++.h>
using namespace std;
#define COOL ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
 
void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> h(n), s(n);
    for(auto &it : h){
        cin >> it;
    }
    for(auto &it : s)
        cin >> it;
    vector<vector<int> >dp(n+1, vector<int> (x+1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= x; j++){
            int rem = j - h[i-1];
            dp[i][j] = dp[i-1][j];
            if(rem >= 0)
                dp[i][j] = max(dp[i-1][j], dp[i-1][rem] + s[i-1]);
        }
    }
    cout << dp[n][x] <<"\n";
 
}
 
 
int main() {
    COOL
    solve();
 
 
    return 0;
}
