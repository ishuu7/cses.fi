#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define loop(i,a,b) for(ll i = (ll)a ; i < (ll)b ; i++)
#define rtloop(i,a,b) for(ll i = (ll)a; i >= (ll)b; i--)
#define pb push_back
#define mp make_pair
#define yo(a) if(local == 'N'){cerr <<#a <<" = " << a <<"\n";}
#define COOL ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
const ll N = 1000;
const ll mod = 1e9 + 7;

 
vector<vector<char> >v(N, vector<char>(N));
vector<vector<ll> >dp(N+1, vector<ll>(N+1, -1));
ll n;
ll solve(ll r, ll c){
	if(r >= n || c >= n || v[r][c] == '*'){
		return 0;
	}
	if(r == n-1 && c == n-1)
		return 1;
	if(dp[r][c] != -1)
		return dp[r][c];
	ll ans = 0;
	ans = (solve(r+1, c)%mod  + solve(r, c+1)%mod)%mod;
	dp[r][c] = ans;
	return ans;
}
 
 
 
int main() {
    COOL
    cin >> n;
    loop(i,0,n){
    	loop(j,0,n){
    		cin >> v[i][j];
    	}
    }
    cout << solve(0, 0) <<"\n";

 
    return 0;
}
