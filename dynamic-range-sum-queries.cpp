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
    #define dbg(...)
#endif
struct Fenwick {
    vector<ll> tree;
    int n;

    Fenwick(int n) : n(n) {
        tree.assign(n, 0);
    }

    void point_add(int pos, ll val) {
        for (; pos < n; pos |= (pos + 1)) {
            tree[pos] += val;
        }
    }

    ll find_sum(int r) { // [0, r]
        ll ans = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            ans += tree[r];
        }
        return ans;
    }

    ll find_sum(int l, int r) { // [l, r)
        return find_sum(r - 1) - find_sum(l - 1);
    }
};
int solve() {
    int n; cin >> n;
    int q; cin >> q;
    Fenwick ans(n);
    vector<ll> a(n);
    for (ll &val : a) {
        cin >> val;
    }
    for (ll i = 0; i < n; i++) {
        ans.point_add(i,a[i]);
    }
    while(q--) {
        int  t; cin >> t;
        if (t == 1) {
            int k,u;cin >> k >> u;
            k--;
            ans.point_add(k,(u-a[k]));
            a[k] = u;
        }
        else {
            int da,b; cin >> da >> b;
            cout << ans.find_sum(da-1,b) << endl;
        }
    }
    return 0;
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
