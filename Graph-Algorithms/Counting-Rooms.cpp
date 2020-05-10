#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define loop(i,a,b) for(ll i = (ll)a ; i < (ll)b ; i++)
#define rtloop(i,a,b) for(ll i = a; i >= b; i--)
#define pb push_back
#define mp make_pair
#define debug(a) cerr << #a <<" = " << a <<"\n";
#define COOL ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
 
int n, m;
 
vector<vector<bool> > visited(1002, vector<bool> (1002, false));


void dfs(int x, int y, vector<vector<char> > &board){
    if(board[x][y] == '.' && visited[x][y] == false){
        visited[x][y] = true;
        dfs(x, y+1, board);
        dfs(x, y-1, board);
        dfs(x+1,y, board);
        dfs(x-1, y, board);
    }
    return;
}
 
int main() {
    COOL
    cin >> n >> m;
    vector<vector<char> > board(n+2, vector<char> (m+2, '*'));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> board[i][j];
        }
    }
    int count = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(board[i][j] == '.' && visited[i][j] == false){
                dfs(i, j, board);
                count ++;
            }
        }
    }
    cout << count <<"\n";
 
    return 0;
}
