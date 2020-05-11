#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define loop(i,a,b) for(ll i = (ll)a ; i < (ll)b ; i++)
#define rtloop(i,a,b) for(ll i = (ll)a; i >= (ll)b; i--)
#define pb push_back
#define mp make_pair
#define yo(a) if(local == 'N'){cerr <<#a <<" = " << a <<"\n";}
#define COOL ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
char local = '0';
 
const int N = 1e5;
vector<int> adj[N+1];
bool visited[N+1] ={false};
 
void dfs(int v){
    visited[v] = true;
    for(int u : adj[v]){
        if(!visited[u])
            dfs(u);
    }
}
 
int main() {
    COOL
    #ifdef N
        //local = 'N';
        freopen("in.txt", "r", stdin);
        freopen("op.txt", "w", stdout);
    #endif
 
    int n, m;
    cin >> n >> m;
    int a, b;
    loop(i,0,m){
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1);
    int cc = 0;
    vector<pair<int, int> >v;
    for(int i = 1; i <= n ;i++){
        if(!visited[i]){
            dfs(i);
            cc ++;
            v.pb({i-1, i});
        }
    }
    cout << cc <<"\n";
    for(auto it : v){
        cout << it.first << " " << it.second <<"\n";
    }
 
    return 0;
}
