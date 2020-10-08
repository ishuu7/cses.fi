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
void out(T arr[], int n)
{
    for (int i = 0; i < n; i++) {
        out(arr[i]);
        cout << " ";
    }
}

template <typename T>
void out(vector<T> &arr)
{

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
        int n;
        cin >> n;

        if(n == 1 || n == 2) {
                cout << "NO\n";
                return;
        }



        if(n % 4 == 0) {
                cout <<"YES\n";
                cout << n / 2 <<"\n";
                int i = 1 , j = n;
                int cc = 0;
                while(cc != n / 2) {
                        cout << i << " " << j <<" ";
                        j--;
                        i++;
                        cc += 2;
                }
                cout <<"\n";
                cout << n / 2 <<"\n";
                while(cc != n) {
                        cout << i << " " << j <<" ";
                        j--;
                        i++;
                        cc += 2;
                }
                cout <<"\n";
        }
        else if((n - 3) % 4 == 0) {
                cout <<"YES\n";
                cout << n / 2 + 1 <<"\n";
                cout << "1 2 ";
                int i = 4, j = n;

                int cc = 2;

                while(cc != n / 2 + 1) {
                        cout << i << " " << j <<" ";
                        i++;
                        j--;
                        cc += 2;
                }

                cout <<"\n";

                cout << n / 2 <<"\n";

                cout << "3 ";
                cc++;

                while(cc != n) {
                        cout << i <<" " << j <<" ";
                        i++;
                        j--;
                        cc += 2;
                }
        }
        else {
                cout <<"NO\n";
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
        // rep(i,1,t + 1)
                solve();
        return 0;
}


