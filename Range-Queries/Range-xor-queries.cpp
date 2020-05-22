#include <bits/stdc++.h>
using namespace std;
#define int long long
#define loop(i,a,b) for(int i = (int)a ; i < (int)b ; i++)
#define rtloop(i,a,b) for(int i = (int)a; i >= (int)b; i--)
#define pb push_back
#define mp make_pair
#define yo(a) if(local == 'L'){cerr <<#a <<" = " << a <<"\n";}
#define COOL ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
//char local = '0';

const int N = 2e5 + 1;

int a[N], t[4*N];

void build(int v, int tl, int tr) {
    if(tl == tr){
        t[v] = a[tl];
        return;
    }
    int tm = (tr + tl) / 2;
    build(v*2, tl, tm);
    build(v*2 + 1, tm+1, tr);
    t[v] = (t[2*v] ^ t[2*v + 1]);
}

int sum(int v, int tl, int tr, int l, int r) {
    if(tl > r || tr < l)
        return 0;
    if(tl >= l && tr <= r)
        return t[v];
    int tm = (tl + tr) / 2;
    return (sum(v*2, tl, tm, l, r) ^ sum(v*2 + 1, tm+1, tr, l, r));
}


int32_t main() {
    COOL
    #ifdef L
        //local = 'L';
        freopen("in.txt", "r", stdin);
        freopen("op.txt", "w", stdout);
    #endif
    int n, q;
    cin >> n >> q;
    loop(i, 1, n+1)cin >> a[i];
    build(1, 1, n); 
    int l1, r1;
    while(q--) {
        cin >> l1 >> r1;
        cout << sum(1, 1, n, l1, r1) << "\n";
    }
    return 0;
}
