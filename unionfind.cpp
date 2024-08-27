// : https://judge.yosupo.jp/problem/unionfind
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

struct DSU {
    vector<int> pr;
    vector<int> sz;
    int n;

    DSU(int n) : n(n) {
        pr.resize(n);
        sz.resize(n);
        iota(pr.begin(), pr.end(), 0);
        for_each(sz.begin(), sz.end(),[](int& x){ x = 0;});
    }

    inline int findpr(int v) {
        return (v == pr[v] ? v : (pr[v] = findpr(pr[v])));
    }

    inline bool check(int a, int b) {
        return findpr(a) == findpr(b);
    }

    inline bool unite(int v, int u) {
        v = findpr(v);
        u = findpr(u);
        if (u == v) {
            return false;
        } else {
            if(sz[v] > sz[u]) swap(u,v);
            sz[u] += sz[v];
            pr[v] = u;
            return true;
        }
    }
};
int solve()
{
    int n;
    if (!(cin >> n)) {
        return 1;
    }
    queue<vector<int>> q; // t,u,v
    int qu;
    cin >> qu;
    for (ll i = 0; i < qu; i++) {
        vector<int> t(3);
        for (ll j = 0; j < 3; j++) {
            cin >> t[j];
        }
        q.push(t);
    }
    DSU dsu(n);
    auto pval = [&](int x) { cout << x << endl; };
    while (!q.empty()) {
        auto now = q.front();
        q.pop();
        assert(sz(now) == 3);
        if (now[0] == 0) {
            dsu.unite(now[1], now[2]);
        } else {
            if (dsu.check(now[1], now[2]))
                pval(1);
            else
                pval(0);
        }
    }
    return 1;
}

int32_t main() {
    //sieve(2e5+10);
    ios::sync_with_stdio(0); cin.tie(0); int TET = 1;
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
