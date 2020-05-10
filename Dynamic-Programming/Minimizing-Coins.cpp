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
		return 0;
	if(rem < 0){
		return INT_MAX;
	}
	if(dp[rem] != -1)
		return dp[rem];
	ll ans = INT_MAX;
	loop(i,0,n){
		ans = min(ans, 1 + solve(rem - a[i]));
	}
	dp[rem] = ans;
	return ans;
}

int main() {
    COOL
    cin >> n >> x;
    loop(i,0,n){
    	cin >> a[i];
    }
    ll ans = solve(x);
    if(ans == INT_MAX)
    	ans = -1;
    cout << ans <<"\n";
    return 0;
}
