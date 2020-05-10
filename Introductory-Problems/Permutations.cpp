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
    if(n <= 3 && n != 1){
        cout <<"NO SOLUTION\n";
        return;
    }
    ll odd, even;
    if(n&1){
        odd = n;
        even = n-1;
    }
    else{
        even = n;
        odd = n-1;
    }
    for(int i = odd; i >= 1; i -= 2){
        cout << i <<" ";
    }
    for(int i = even; i > 0; i -= 2){
        cout << i << " ";
    }
 
 
}
 
 
 
int main() {
    COOL
    solve();
 
    return 0;
}
