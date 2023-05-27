// : https://cses.fi/problemset/task/1669
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
    int cycle_start = -1;
    int cycle_end = -1;
    vector<int> p(n,-1);
    function<bool(int,int)> dfs = [&](int v, int par = -1) {
        used[v] = 1;
        for(auto u : g[v]) {
            d(u,v);
            if(u == par) continue ;
            if(used[u] == 1) {
                d(u, 1);
                cycle_start = u;
                cycle_end = v;
                return true;
            }
            p[u] = v;
            if (dfs(u,v)) {
                d(u);
                return true;
            }
            d(p);
        }
        return false;
    };
    for (int i = 0; i < n; i++) {
        if (used[i] == 0) {
            if(dfs(i, -1)) break;
        }
    }
    if (cycle_end == -1 ) {
        cout << "IMPOSSIBLE" << endl;
    }
    int cur = cycle_end;
    vector<int> a;
    while(cur != cycle_start) {
        a. push_back(cur);
        cur = p[cur];
    }
    a. push_back(cycle_start);
    a. push_back(cycle_end);
    cout << sz(a) << endl;
    for_each( a.begin(), a.end(), [](int x){ cout << x  + 1<< " " ;});
    cout << endl;
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
