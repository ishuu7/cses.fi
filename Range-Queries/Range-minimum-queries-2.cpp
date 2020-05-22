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
    t[v] = min(t[2*v], t[2*v + 1]);
}

int getMin(int v, int tl, int tr, int l, int r) {
    if(tl > r || tr < l)
        return INT_MAX;
    if(tl >= l && tr <= r)
        return t[v];
    int tm = (tl + tr) / 2;
    return min(getMin(v*2, tl, tm, l, r), getMin(v*2 + 1, tm+1, tr, l, r));
}

void update(int v, int tl, int tr, int pos, int newVal) {
    if(tl == tr){
        t[v] = newVal;
        a[tl] = newVal;
        return;
    }
    int tm = (tl + tr) / 2;
    if(pos <= tm)
        update(v*2, tl, tm, pos, newVal);
    else
        update(v*2 + 1, tm+1, tr, pos, newVal);
    t[v] = min(t[v*2], t[v*2 + 1]);
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
    int l1, r1, x;
    while(q--) {
        cin >> x >> l1 >> r1;
        if(x == 2)
            cout << getMin(1, 1, n, l1, r1) << "\n";
        else
            update(1, 1, n, l1, r1);
    }
    return 0;
}
