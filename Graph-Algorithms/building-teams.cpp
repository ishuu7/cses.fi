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
int dis[N+1];
int parent[N+1];
vector<bool> col(N+1, false);
 
bool dfsBipartite(int v, bool c){
    col[v] = c;
    visited[v] = 1;
    for(int u : adj[v]){
        if(!visited[u]){
            if(!(dfsBipartite(u, c^1)))
                return false;
        }
        else{
            if(col[v] == col[u])
                return false;
        }
    }
    return true;
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
    loop(i, 1, n+1){
        if(!visited[i])
            if(!dfsBipartite(i, 0)){
                cout << "IMPOSSIBLE\n";
                return 0;
            }
    }
    loop(i,1,n+1){
        if(!col[i]){
            cout << 2 <<" ";
        }
        else cout << 1 <<" ";
    }
    return 0;
}
