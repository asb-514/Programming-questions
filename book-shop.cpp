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

int solve()
{
    int n;
    cin >> n;
    int x;
    cin >> x;
    vector<ll> h(n);
    for (ll& val : h) {
        cin >> val;
    }
    vector<ll> s(n);
    for (ll& val : s) {
        cin >> val;
    }
    vector<ll> dp(x + 10, -1e9);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        vector<ll> dpt(x + 10, -1e9);
        for (int j = 0; j <= x; j++) {
            dpt[j] = dp[j];
        }
        for (int j = 0; j <= x; j++) {
            if (dp[j] != -1e9 && j + h[i] <= x + 3) {
                dpt[j + h[i]] = max(dp[j + h[i]], dp[j] + s[i]);
            }
        }
        dp = dpt;
    }
    ll ans = 0;
    dbg(dp);
    for (int i = 0; i <= x; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
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
