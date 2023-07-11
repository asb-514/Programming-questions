#ifdef ONPC
#define _GLIBCXX_DEBUG
// #include "bits/stdc++.h"
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
const int inf = 1e9;
int solve()
{
    int n;
    if (!(cin >> n)) {
        return 1;
    }
    
    int q;
    cin >> q;
    vector<int> tree(4 * n);
    vector<int> a(n);
    for (int& val : a) {
        cin >> val;
    }
    function<void(int, int, int)> build = [&](int v, int l, int r)
    {
        if (l == r - 1) {
            tree[v] = a[l];
            return ;
        }
        int mid = (l + r) >> 1;
        build(2 * v, l, mid);
        build(2 * v + 1, mid, r);
        tree[v] = min(tree[2 * v], tree[2 * v + 1]);
        return;
    };
    function<int(int, int, int, int, int)> find = [&](int v, int l, int r, int tl, int tr)
    {
        if (l >= tl && r <= tr) {
            return tree[v];
        }
        if (l >= tr || r <= tl) {
            return inf;
        }
        int mid = (l + r) >> 1;
        return min(find(2 * v, l, mid, tl, tr), find(2 * v + 1, mid, r, tl, tr));
    };
    function<void(int, int, int, int, int)> update = [&](int v, int l, int r, int ti, int val)
    {
        if (ti >= r || ti < l) {
            return;
        }
        if (ti == l && l == r - 1) {
            tree[v] = val;
            return;
        }
        int mid = (l + r) >> 1;
        update(2 * v, l, mid, ti, val);
        update(2 * v + 1, mid, r, ti, val);
        tree[v] = min(tree[2 * v], tree[2 * v + 1]);
        return;
    };
    build(1,0,n);
    while(q--) {
        int t; cin >> t;
        if (t == 1) {
            int k,u;
            cin >> k >> u;
            k--;
            update(1,0,n,k,u);
        }
        else {
            int aa,b;
            cin >> aa >> b;
            cout << find(1,0,n,aa-1,b) << endl;
        }
    }
    return 0;
}

int32_t main()
{
    // sieve(2e5+10);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1e9;
    for (int i = 1; i <= TET; i++) {
        if (solve()) {
            break;
        }
#ifdef ONPC
        cout << "__________________________" << endl;
#endif
    }
#ifdef ONPC
    cerr << endl
         << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
