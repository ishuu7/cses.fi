#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define loop(i,a,b) for(ll i = (ll)a ; i < (ll)b ; i++)
#define rtloop(i,a,b) for(ll i = (ll)a; i >= (ll)b; i--)
#define pb push_back
#define mp make_pair
#define yo(a) cerr <<#a <<" = " << a <<"\n";
#define COOL ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const ll N = 1e6;
const ll mod = 1e9 + 7;
vector<ll> dp(N+1, -1);
ll solve(ll curr){
	if(curr == 0)
		return 1;
	if(curr < 0)
		return 0;
	if(dp[curr] != -1){
		return dp[curr];
	}
	ll ans = (solve(curr - 1)%mod + solve(curr - 2)%mod  + solve(curr -3)%mod + solve(curr - 4)%mod + solve(curr - 5)%mod + solve(curr - 6)%mod)%mod;
	dp[curr] = ans;
	return ans;
}
 
 
int main() {
    COOL
    ll n;
    cin >> n;
    ll ans = solve(n);
    cout << ans <<"\n"; 
    return 0;
}
