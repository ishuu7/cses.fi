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
 
bool isValid(int x, int y, int n, int m) {
        if(x >= 0 && y >= 0 && x < n && y < m)
                return true;
        return false;
}
 
void bfs(vector<pair<int, int>>& monsters, vector<vector<int>>& timeMonster, int n, int m, vector<vector<char>>& mat) {
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<pair<int, int>, int>>q;
        for(int i = 0; i < monsters.size(); i++) {
                q.push({{monsters[i]}, 0});
                timeMonster[monsters[i].first][monsters[i].second] = 0;
                visited[monsters[i].first][monsters[i].second] = true;
        }
        int dir[4] = {-1, 1, 0, 0};
        int dir2[4] = {0, 0, 1, -1};
 
        while(q.size()) {
                pair<pair<int, int>, int> now = q.front();
                q.pop();
                int currTime = now.second;
                int curX = now.first.first;
                int curY = now.first.second;
                timeMonster[curX][curY] = currTime;
                for(int i = 0; i < 4; i++) {
                        int X = curX + dir[i];
                        int Y = curY + dir2[i]; 
                        if(isValid(X, Y, n, m) && !visited[X][Y] && mat[X][Y] != '#') {
                                q.push({{X, Y}, currTime + 1});
                                visited[X][Y] = true;
                        }
                }
        }
}
 
pair<bool, vector<char>> bfsMan(int xx, int yy, vector<vector<int>>& time, int n, int m, vector<vector<char>>& mat, vector<vector<int>>& timeMonster) {
        o(xx)
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<pair<int, int>, int>>q;
        q.push({{xx, yy}, 0});
        visited[xx][yy] = true;
 
        bool ans = false;
        vector<char> a;
 
        map<pair<int, int>, pair<int, int>> par;
        par[{xx, yy}] = {-1, -1};
 
        int dir[4] = {-1, 1, 0, 0};
        int dir2[4] = {0, 0, 1, -1};
 
        int rX, rY;
 
        while(q.size()) {
                pair<pair<int, int>, int> now = q.front();
                q.pop();
                int currTime = now.second;
                int curX = now.first.first;
                int curY = now.first.second;
 
                if(timeMonster[curX][curY] > currTime) {
                        if(curX == 0 || curY == 0 || curX == n - 1 || curY == m - 1) {
                                ans = true;
                                o(curX, curY)
                                rX = curX;
                                rY = curY;
                                break;
                        }
                        for(int i = 0; i < 4; i++) {
                                int X = curX + dir[i];
                                int Y = curY + dir2[i]; 
                                if(isValid(X, Y, n, m) && !visited[X][Y] && mat[X][Y] != '#') {
                                        par[{X, Y}] = {curX, curY};
                                        q.push({{X, Y}, currTime + 1});
                                        visited[X][Y] = true;
                                }
                        }
                }
        }
 
        if(ans) {
                pair<int, int> curP = {rX, rY};
                while(par[curP].first != -1) {
                        pair<int, int> go = par[curP];
                        if(go.first - curP.first == 1) {
                                a.pb('U');
 
                        } else if(go.first - curP.first == -1) {
                                a.pb('D');
                        } else if(go.second - curP.second == 1) {
                                a.pb('L');
 
                        } else {
                                a.pb('R');
                        }
                        curP = go;
                }
        }
        return {ans, a};
 
 
}
 
 
void solve() {
        int n, m;
        cin >> n >> m;
        vector<vector<char> > mat(n, vector<char>(m));
        vector<pair<int, int>> monsters;
        int x, y;
 
        for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                        cin >> mat[i][j];
                        if(mat[i][j] == 'M') {
                                monsters.pb({i, j});
                        }
                        else if(mat[i][j] == 'A') {
                                x = i;
                                y = j;
                        }
                }
        }
 
 
        // multisource bfs
 
        vector<vector<int> > timeMonster(n, vector<int>(m, 1005)), time(n, vector<int>(m, 1000));
        bfs(monsters, timeMonster, n, m, mat);
        
        pair<bool, vector<char>> ans = bfsMan(x, y, time, n, m, mat, timeMonster);
        reverse(ans.second.begin(), ans.second.end());
        o(ans.second);
        if(!ans.first) {
                cout <<"NO\n";
                return;
        }
        cout <<"YES\n";
        cout << ans.second.size() <<"\n";
        for(auto &it : ans.second) {
                cout << it;
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
