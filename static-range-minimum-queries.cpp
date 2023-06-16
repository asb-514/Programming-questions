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
#define inf 1e15
int solve()
{
    ll n;
    ll q;
    cin >> n >> q;
    vector<ll> a(n);
    for (ll& val : a) {
        cin >> val;
    }
    vector<ll> tree(4 * n + 1);
    function < void (ll,ll,ll) > build = [&](ll v, ll l, ll r) {
        if (l + 1 == r) {
            tree[v] = a[l];
            return ;
        }
        ll mid = (l + r) >> 1;
        build(2*v,l,mid);
        build(2*v + 1,mid,r);
        tree[v] = min(tree[2*v] ,tree[2*v +1 ]);
        return ;
    };
    //[l,r)
    build(1,0,n);
    function <ll (ll,ll,ll,ll,ll) > find_min = [&](ll v,ll l,ll r,ll tl, ll tr) {
        if (l >= tr || r <= tl) {
            return (ll)1e15;
        }
        if (l >= tl && r <= tr) {
            return tree[v];
        }
        ll mid = (l + r) >> 1;
        return min(find_min(2*v ,l,mid,tl,tr),find_min(2*v + 1,mid,r,tl,tr));
    };
    while(q--) {
        ll x;
        ll y;
        cin >> x >> y;
        cout << find_min(1,0,n,x-1,y) << endl;
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
