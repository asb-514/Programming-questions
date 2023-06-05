// #include "coin-combinations-II.h"

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
    int ts;
    cin >> ts;
    vector<ll> a(n);
    for (ll& val : a) {
        cin >> val;
    }
    vector<ll> dp(ts + 10, 0);
    dp[0] = 1;
    for (auto c : a) {
        for (int i = 0; i < ts + 3; i++) {
            if (i + c > ts + 1) {
                continue;
            }
            dp[i + c] += dp[i];
            dp[i + c] %= (ll)(1e9 + 7);
        }
    }
    cout << dp[ts] << endl;
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
