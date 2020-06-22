#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define COOL ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


string a,b;
int n,m;
int dp[5010][5010];

int fun(int p1, int p2) {
      // if any of the pointer is 0, that means string is empty and we return
      // size of the other remaining string.
      if(p1 == 0)
            return p2;
      if(p2 == 0)
            return p1;
      if(dp[p1][p2] != -1)
            return dp[p1][p2];
      int ans;
      if(a[p1-1] == b[p2-1])
            ans = fun(p1 - 1, p2 - 1);
      else
            ans = 1 + min({fun(p1 - 1, p2 - 1), fun(p1 - 1, p2), fun(p1, p2 - 1)});
      return dp[p1][p2] = ans;
}



int32_t main() {
      COOL
      #ifdef L
            //local = 'L';
            freopen("in.txt", "r", stdin);
            freopen("op.txt", "w", stdout);
      #endif
      // int tc;
      // cin >> tc;
      // while(tc--)
            // solve();
      cin >> a >> b;
      n = a.size();
      m = b.size();     
      memset(dp, -1, sizeof dp);
      int ans = fun(n, m);
      cout << ans <<"\n";

      return 0;
}

