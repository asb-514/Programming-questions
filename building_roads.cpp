// : https://cses.fi/problemset/task/1666
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
    set<int> root;
    function< void (int) > dfs = [&](int v) {
        used[v] = 1;
        for(auto u : g[v]) {
            if (used[u] == 1) {
                continue;
            }
            dfs(u);
        }
    };
    for (ll i = 0; i < n; i++) {
        if (used[i] == 0) {
            root.insert(i);
            dfs(i);
        }
    }
    cout << sz(root) - 1 << endl;
    for(auto it = root.begin(); next(it,1) != root.end() ; it++ ) {
        cout << *it + 1 <<  " " << *next(it , 1) + 1 << endl;
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
