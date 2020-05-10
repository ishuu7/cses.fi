#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define loop(i,a,b) for(ll i = (ll)a ; i < (ll)b ; i++)
#define rtloop(i,a,b) for(ll i = a; i >= b; i--)
#define pb push_back
#define mp make_pair
#define debug(a) cerr << "#a = " << a <<"\n";
#define COOL ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
 
 
void solve(ll n){
    ll a[n];
    ll sum2  = (n*(n+1))/2;
    ll sum = 0;
    loop(i,0,n-1){
        cin >> a[i];
        sum += a[i];
    }
    cout << sum2 - sum <<"\n";
 
}
 
int main() {
    COOL
    ll n;
    cin >> n;
    solve(n);
    
 
 
    return 0;
}
