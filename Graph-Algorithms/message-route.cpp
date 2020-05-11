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


void bfsSSSP(int v){ // for unweighted graph
    parent[v] = 1;
    dis[v] = 0;
    queue<int> q;
    q.push(v);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        int d = dis[curr] + 1;
        for(int u : adj[curr]){
            if(d >= dis[u])continue;
            dis[u] = d;
            parent[u] = curr;
            q.push(u);
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
    for(int i = 0; i <= N; i ++){
        dis[i] = n+1;
        parent[i] = -1;
    }
    parent[1] = 1;
    dis[1] = 0;
    bfsSSSP(1);
    if(dis[n] == n+1){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    vector<int> ans;
    while(n > 1){
        ans.pb(n);
        n = parent[n];
    }
    ans.pb(1);
    reverse(ans.begin(), ans.end());
    cout << ans.size()<<"\n";
    for (int i : ans){
        cout << i <<" ";
    }
    cout << "\n";


    return 0;
}




