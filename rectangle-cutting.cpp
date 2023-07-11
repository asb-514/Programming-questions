#if ONPC
#define _GLIBCXX_DEBUG
#else
#include <bits/stdc++.h>
#endif

#define sz(a) ((int)((a).size()))
#define char unsigned char
#define pi 3.141592653589793238

using namespace std;
// mt19937 rnd(239);
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;
#ifdef ONPC
#include "debug.h"
#else
#define dbg(...)
#endif

int solve()
{
    int a;
    if (!(cin >> a)) {
        return 1;
    }
    int b;
    cin >> b;
    vector<vector<ll>> dp(505, vector<ll>(505, 1e14));
    for (int i = 0; i < 505; ++i) {
        dp[i][0] = 0;
    }
    for (int i = 0; i < 505; ++i) {
        dp[0][i] = 0;
    }
    for (int i = 1; i < a + 1; ++i) {
        for (int j = 1; j < b + 1; ++j) {
            if (i == j)
                dp[i][j] = 1;
            for (int k = 1; k < i; k++) {
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j]);
            }
            for (int k = 1; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k]);
            }
        }
    }
    cout << dp[a][b] - 1 << endl;
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
    }
#ifdef ONPC
    cout << "__________________________" << endl;
#endif
#ifdef ONPC
    cerr << endl
         << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
    return 0;
}
