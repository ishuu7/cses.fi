#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define loop(i,a,b) for(ll i = (ll)a ; i < (ll)b ; i++)
#define rtloop(i,a,b) for(ll i = (ll)a; i >= (ll)b; i--)
#define pb push_back
#define mp make_pair
#define yo(a) cerr <<#a <<" = " << a <<"\n";
#define COOL ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const ll N = 1e2;
const ll mod = 1e9 + 7;
const ll X = 1e6;

ll n, x;
ll a[N];
vector<ll> dp(X+1, -1);

ll solve(ll rem){
	if(rem == 0)
		return 1;
	if(rem < 0){
		return 0;
	}
	if(dp[rem] != -1)
		return dp[rem];
	ll ans = 0;
	loop(i,0,n){
		ans += (solve(rem - a[i])%mod);
		ans %= mod;
	}
	dp[rem] = ans%mod;
	return ans;
}
 
 
int main() {
    COOL
    cin >> n >> x;
    loop(i,0,n){
    	cin >> a[i];
    }
    ll ans = solve(x);
    cout << ans <<"\n";
    return 0;
}
