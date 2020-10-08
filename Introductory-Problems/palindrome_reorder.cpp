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
 
void solve() {
        string s;
        cin >> s;
        int freq[26] = {};
        for(auto &it : s) {
                freq[it - 'A']++;
        }
        int cc = 0;
        for(int i = 0; i < 26; i++) {
                if(freq[i] % 2)
                        cc++;
        }
        if(cc > 1) {
                cout <<"NO SOLUTION\n";
                return;
        }
        int l = 0, r = s.size() - 1;
        int mid = (r + 1) / 2;
        for(int i = 0; i < 26; i++) {
                if(freq[i] % 2) {
                        s[mid] = (char)(i + 'A');
                        freq[i] -= 1;
                }
                while(freq[i] != 0) {
                        s[l] = (char)(i + 'A');
                        s[r] = (char)(i + 'A');
                        l++;
                        r--;
                        freq[i] -= 2;
                }
        }
        cout << s <<"\n";
 
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
