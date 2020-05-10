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
    string s;
    cin >> s;
    ll count = 1;
    ll n = s.size();
    ll maxi = count;
    loop(i,0,n-1){
        if(s[i] == s[i+1]){
            count++;
        }
        else{
            count = 1;
        }
        maxi = max(maxi, count);
    }
    cout << maxi <<"\n";
}
 
 
 
int main() {
    COOL
    solve();
    return 0;
}
