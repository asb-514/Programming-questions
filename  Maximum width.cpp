// #include " Maximum width.h"

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

int solve() {
    ll n;
    if (!(cin >> n)) {
        return 1;
    }
    ll m; cin >> m;
    string a; cin >> a;
    string b; cin >> b;
    vector<ll> l(m);
    vector<ll> r(m);
    ll j = 0;
    for (ll i = 0; i < m; i++) {
        while(j < n && a[j] != b[i]) j++;
        l[i] = j;
    }
    j = n-1;
    for (ll i = m-1 ; i > -1; i--) {
        while (j>-1 && a[j] != b[i]) {
            j--;
        }
        r[i] = j;
    }
    ll ans = 0;
    for (ll i = 0; i < m-1; i++) {
        ans = max(ans , r[i + 1] - l[i]);
    }
    cout << ans << endl;
    return 0;
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
