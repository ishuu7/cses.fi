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
int visited[N+1];
int dis[N+1];
int parent[N+1];
int point;
int par2;
void dfs(int v, int par){
    if(visited[v] == 1){
        point = v;
        par2 = par;
        return;
    }
    parent[v] = par;
    visited[v]++;
    for(int u : adj[v]){
        if(point != 0)
            return;
        if(u != par){
            dfs(u, v);
        }
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
    for(int i = 1; i <= N; i++){
        if(visited[i] == 0){
            dfs(i, 0);
        }
    }
    if(point == 0){
        cout <<"IMPOSSIBLE\n";
        return 0;
    }
    vector<int> ans;
    int te = par2;
    ans.pb(point);
    while(te != point){
        ans.pb(te);
        te = parent[te];
    }
    ans.pb(point);
    cout << ans.size() <<"\n";
    for(int i : ans){
        cout << i <<" ";
    }
    cout <<"\n";
    
    return 0;
}
