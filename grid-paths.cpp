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
    vector<vector<ll>> g(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char t;
            cin >> t;
            g[i][j] = 1;
            if (t == '.') {
                g[i][j] = 0;
            }
        }
    }
    if (g[0][0] == 1) {
        cout << 0 << endl;
        return 0;
    }
    // first square is not a trap here
    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    dp[0][0] = 1;
    for (int i = 1; i < n; i++) {
        if (g[0][i] != 1)
            dp[0][i] += dp[0][i - 1];
        dp[0][i] %= (ll)(1e9 + 7);
    }
    for (int i = 1; i < n; i++) {
        if (g[i][0] != 1)
            dp[i][0] += dp[i - 1][0];
        dp[i][0] %= (ll)(1e9 + 7);
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (g[i][j] == 0) {
                dp[i][j] += (dp[i - 1][j]) + dp[i][j - 1];
                dp[i][j] %= (ll)(1e9 + 7);
            }
        }
    }
    cout << dp[n - 1][n - 1] << endl;
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
