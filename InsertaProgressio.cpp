// #include "InsertaProgressio.h"

// https://codeforces.com/problemset/problem/1671/D
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
#define d(...)
#endif

int solve()
{
    int n;
    int x;
    cin >> n >> x;
    vector<ll> a(n);
    for (ll& val : a) {
        cin >> val;
    }
    ll emi = abs(1 - a[0]);
    ll emx = abs(x - a[0]);
    for (ll i = 0; i < n; i++) {
        emi = min(emi, 2 * abs(1 - a[i]));
        emx = min(emx, 2 * abs(x - a[i]));
    }
    emi = min(emi, abs(a[n - 1] - 1));
    emx = min(emx, abs(x - a[n - 1]));
    if (x <= *max_element(a.begin(), a.end())) {
        emx = 0;
    }
    ll ans = 0;
    for (ll i = 0; i < n - 1; i++) {
        ans += abs(a[i + 1] - a[i]);
    }
    ans
        += (emi + emx);
    cout << ans << endl;
    return 0;
}

int32_t main()
{
    // sieve(2e5+10);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1e9;
    cin >> TET;
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
