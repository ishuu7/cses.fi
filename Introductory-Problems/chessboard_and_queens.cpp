#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,a,b) for(int i = (int)a ; i < (int)b ; i++)
#define rrep(i,a,b) for(int i = (int)a; i >= (int)b; i--)
#define pb push_back
#define vi vector<int>
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
    out(p.ff);
    cout << ",";
    out(p.ss);
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
 
 
 
bool isValid(vector<vector<char>>& curr, int row, int col) {
        // curr col mai koi hai kya
        for(int i = 0; i < row; i++) {
                if(curr[i][col] == 'Q')
                        return false;
        }
        // diagonals
        int j = col - 1;
        for(int i = row - 1; i >= 0 && j >= 0; i--, j--) {
                if(curr[i][j] == 'Q')
                        return false;
        }
 
        j = col + 1;
        for(int i = row - 1; i >= 0 && j < 8; i--, j++) {
                //o(i, j);
                if(curr[i][j] == 'Q')
                        return false;
        }
        return true;
}
 
int ans = 0;
 
void sol(vector<vector<char>>& curr, int row) {
        if(row == 8) {
                ans++;
                return;
        }
 
 
        for(int i = 0; i < 8; i++) {
                if(curr[row][i] == '.' && isValid(curr, row, i)) {
                        curr[row][i] = 'Q';
                        sol(curr, row + 1);
                        curr[row][i] = '.';
                }
        }
 
}
 
void solve() {
        vector<vector<char> > s(8, vector<char>(8));
        rep(i, 0, 8) {
                rep(j, 0, 8) {
                        cin >> s[i][j];
                }
        }
        sol(s, 0);
 
        cout << ans <<"\n";
 
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
        // rep(i,1,t + 1)
                solve();
        return 0;
}
