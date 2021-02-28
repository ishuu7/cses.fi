#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,a,b) for(int i = (int)a ; i < (int)b ; i++)
#define rrep(i,a,b) for(int i = (int)a; i >= (int)b; i--)
#define pb push_back
#define pii pair<int, int>
 
#define COOL ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define minHeap priority_queue<int, vector<int>, greater<int> >
#define maxHeap priority_queue<int>
 
#define o(...) if(local=='L') {__f(#__VA_ARGS__, __VA_ARGS__); cout<<endl;}
char local = '0';
 
////////////////#####################OUPUT###############///////////////////////
 
template <typename T>
void out(T& n) {
    cout << n;
}
 
template <typename T, typename T1>
void out(pair<T, T1> &p) {
    cout << "(";
    out(p.first);
    cout << ",";
    out(p.second);
    cout << ")";
}
 
template <typename T>
void out(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        out(arr[i]);
        cout << " ";
    }
}
 
template <typename T>
void out(vector<T> &arr) {
 
        cout << "[ ";
        for (int i = 0; i < arr.size(); i++) {
        out(arr[i]);
        if (i!=arr.size()-1)
            cout << ", ";
        }
        cout << " ]";
 
}
 
 
 
template <typename T>
void out(set<T> &arr) {
        for (auto i:arr) {
        out(i);
        cout << " ";
        }
}
 
template <typename T, typename T1>
void out(map<T,T1> &m) {
        for (auto i:m) {
        out(i.first);
        cout<<" -> ";
        out(i.second);
        cout<<", ";
        }
}
 
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
        cout << name << " : ";
        out(arg1);
}
 
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
        const char *comma = strchr(names + 1, ',');
        cout.write(names, comma - names) << " : ";
        out(arg1);
        cout << " | ";
        __f(comma + 1, args...);
}
 
 
////////////////////////////////////END TEMPLATE//////////////////////////////////
 
// Lost
 
 
bool found = false;
map<pair<int, int>, pair<int, int>> parent;
void bfs(int x1, int y1, int n, int m, vector<vector<char>>& mat, vector<vector<bool>>& vis) {
 
        queue<pair<int, int>> q;
 
        vis[x1][y1] = true;
        vector<char> e;
        q.push({x1, y1});
        parent[{x1, y1}] = {-1, -1};
 
        while(q.size()) {
                auto it = q.front();
                q.pop();
                int dir[2] = {-1, 1};
                for(int i = 0; i < 2; i++) {
                        int x = it.first + dir[i];
                        int y = it.second;
                        if(x < 1 || y < 1 || x > n || y > m || mat[x][y] == '#' || vis[x][y] ) {
                                continue;
                        }
                        else {
                                vis[x][y] = true;
                                q.push({x, y});
                                parent[{x, y}] = it;
                                if(mat[x][y] == 'B') {
                                        found = true;
                                        return;
                                }
                        }
                }
 
                for(int i = 0; i < 2; i++) {
                        int x = it.first;
                        int y = it.second + dir[i];
                        if(x < 1 || y < 1 || x > n || y > m || mat[x][y] == '#' || vis[x][y] ) {
                                continue;
                        }
                        else {
                                vis[x][y] = true;
                                q.push({x, y});
                                parent[{x, y}] = it;
                                if(mat[x][y] == 'B') {
                                        found = true;
                                        return;
                                }
                        }
                }
 
        }
 
 
}
 
 
 
void solve() {
        int n, m;
        cin >> n >> m;
        vector<vector<char>>mat(n + 1, vector<char>(m + 1));
        pair<int, int> start, end;
        rep(i, 1, n + 1) {
                rep(j, 1, m + 1) {
                        cin >> mat[i][j];
                        if(mat[i][j] == 'A') {
                                start = {i, j};
                        }
                        else if(mat[i][j] == 'B') {
                                end = {i, j};
                        }
                }
        }
        vector<char> current;
        vector<vector<bool>>vis(n + 2, vector<bool>(m + 2, false));
        bfs(start.first, start.second, n, m, mat, vis);
 
        if(found == 0) {
                cout <<"NO\n";
        }
        else {
                cout <<"YES\n";
                vector<char> ans;
                while(parent[end].first != -1 && parent[end].second != - 1) {
                        pair<int, int> curr = end;
                        pair<int, int> par = parent[end];
                        if(curr.first - par.first == 1) {
                                ans.pb('D');
                        }
                        else if(curr.first - par.first == -1) {
                                ans.pb('U');
 
                        }
                        else if(curr.second - par.second == 1) {
                                ans.pb('R');
                        }
                        else {
                                ans.pb('L');
                        }
                        end = parent[end];
                }
 
                cout << ans.size() <<"\n";
                reverse(ans.begin(), ans.end());
                for(auto &it : ans)  {
                        cout << it;
                }
                
        }
 
}
 
 
signed main() {
        #ifdef L
            local = 'L';
            freopen("in.txt", "r", stdin);
            freopen("op.txt", "w", stdout);
        #endif
        COOL;
        // int t;
        // cin >> t;
        // while(t--)
                solve();
        return 0;
}
