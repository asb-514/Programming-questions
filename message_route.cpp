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
const int N =  1e5 + 2;

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
    auto bfs = [&](int s) {
        queue <int> q;
        q.push(s);
        vector<int> dis(n,0);
        vector<int> p(n,-1);
        used[s] = 1;
        while(!q.empty()) {
            auto v = q.front(); q.pop();
            for(auto u : g[v]) {
                if(used[u] == 1) continue;
                q. push(u);
                used[u] = 1;
                p[u] = v;
                dis[u] = dis[v] + 1;
            }
        }
        vector<int> ans;
        if (dis[n-1] == 0) {
            return ans;
        }
        d(dis,p);
        int cur = n-1;
        while(cur != 0) {
            d(cur);
            int par = p[cur];
            ans. push_back(cur);
            cur = par;
        }
        ans. push_back(0);
        assert(sz(ans) == dis[n-1] + 1);
        reverse( ans.begin(), ans.end());
        return ans;
    };
    vector<int> a = bfs(0);
    if (sz(a) == 0) {
        cout << "IMPOSSIBLE" << endl;
    }
    cout << sz(a) << endl;
    for (ll i = 0; i < sz(a); i++) {
        cout << a[i] + 1 << " ";
    }
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
