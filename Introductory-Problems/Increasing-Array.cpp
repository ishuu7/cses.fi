#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define loop(i,a,b) for(ll i = (ll)a ; i < (ll)b ; i++)
#define rtloop(i,a,b) for(ll i = (ll)a; i >= (ll)b; i--)
#define pb push_back
#define mp make_pair
#define yo(a) cerr <<#a <<" = " << a <<"\n";
#define COOL ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
void solve(){
    ll n;
    cin >> n;
    ll a[n];
    loop(i,0,n)cin >> a[i];
    ll sum = 0;
    loop(i,1, n){
        if(a[i] < a[i-1]){
            sum += a[i-1] - a[i];
            a[i] = a[i-1];
        }
    }
    cout << sum <<"\n";
 
}
 
 
 
int main() {
    COOL
    solve();
    
        
 
 
    return 0;
}
