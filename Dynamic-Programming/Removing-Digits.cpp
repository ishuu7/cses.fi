#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define loop(i,a,b) for(ll i = (ll)a ; i < (ll)b ; i++)
#define rtloop(i,a,b) for(ll i = (ll)a; i >= (ll)b; i--)
#define pb push_back
#define mp make_pair
#define yo(a) if(local == 'N'){cerr <<#a <<" = " << a <<"\n";}
#define COOL ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
const ll N = 1e6;
vector<ll> dp(N+1, -1);
ll n;
ll solve(ll rem){
	if(rem == 0)
		return 0;
	if(dp[rem] != -1)
		return dp[rem];
	ll ans = INT_MAX;
	ll te = rem;
	vector<ll> vv;
	while(te != 0){
		if(te%10 != 0)
			vv.pb(te%10);
		te /= 10;
	}
	for(int i = 0; i < vv.size(); i ++){
		ans = min(ans, 1 + solve(rem - vv[i]));
	}
	dp[rem] = ans;
	return ans;
}
 
 
int main() {
    COOL
    cin >> n;
    ll ans = solve(n);
    cout << ans <<"\n";
    return 0;
}
