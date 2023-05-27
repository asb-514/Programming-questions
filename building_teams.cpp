// : https://cses.fi/problemset/task/1668
#ifdef ONPC
    #define _GLIBCXX_DEBUG
    //#include "bits/stdc++.h"
#else
    #include <bits/stdc++.h>
#endif

#define sz(a) ((int)((a).size()))
#define char unsigned char
#define pi 3.141592653589793238

using namespace std;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;
#ifdef ONPC
    #include "debug.h"
#else
    #define d(...)
#endif
const int N = 1e5 + 2;

vector<int> g[N];
int used[N];

int solve() {
    int n;
    if (!(cin >> n)) {
        return 1;
    }
    int m;
    cin >> m;
    for (int i = 0; i < n; i++) {
        used[i] = 0;
        g[i].clear();
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> grp(n,-1);
    int flag = 1;
    function <void(int)> dfs = [&](int v) {
        for(auto u : g[v]) {
            if(used[u] == 0) { 
                grp[u] = (grp[v] + 1) % 2;
                used[u] = 1;
            }
            else {
                if (grp[u] != (grp[v] + 1)%2) {
                    flag = 0;
                }
                else continue;
            }
            used[u] = 1;
            if (flag == 0) {
                return ;
            }
            dfs(u);
        }
    };
    for (ll i = 0; i < n; i++) {
        if (used[i] != 1) {
            used[i] = 1;
            grp[i] = 0;
            dfs(i);
        }
    }
    if (flag == 0) {
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        for (ll i = 0; i < n; i++) {
            cout << grp[i] + 1 << " ";
        }
        cout << endl ;
    }
    return 1;
}

int32_t main() {
    //sieve(2e5+10);
    ios::sync_with_stdio(0); cin.tie(0); int TET = 1e9;
    for (int i = 1; i <= TET; i++) {
        if (solve()) {break;}
        #ifdef ONPC
            cout << "__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}
