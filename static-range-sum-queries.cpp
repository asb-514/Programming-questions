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

const int N = 2e5 + 2;
ll tree[4 * N];
int solve()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (ll& val : a) {
        cin >> val;
    }
    function<void(ll, ll, ll)> build = [&](ll v, ll l, ll r) { //[l,r)
        if (l == r - 1) {
            tree[v] = a[l];
            return;
        }
        build(2 * v, l, (l + r) >> 1);
        build(2 * v + 1, ((l + r) >> 1), r);
        tree[v] = tree[2 * v] + tree[2 * v + 1];
        return;
    };
    build(1, 0, n);
    function<ll(ll, ll, ll, ll, ll)> fnd = [&](ll v, ll l, ll r, ll tl, ll tr) { //[tl,tr)
        if (l >= tr || r <= tl) {
            return (ll)0;
        }
        if (tl <= l && tr >= r) {
            return tree[v];
        }
        ll mid = (l + r) >> 1;
        return fnd(2 * v, l, mid, tl, tr) + fnd(2 * v + 1, mid, r, tl, tr);
    };
    while (q--) {
        ll x, y;
        cin >> x >> y;
        cout << fnd(1, 0, n, x - 1, y) << endl;
    }
    return 0;
}

int32_t main()
{
    // sieve(2e5+10);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
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
