#if ONPC
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
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;
#ifdef ONPC
#include "debug.h"
#else
#define dbg(...)
#endif
const int N = 5e3 + 3;
const int M = 5e3 + 3;
int solve()
{
    vector<vector<ll>> dp(N + 1, vector<ll>(M + 1, 0));
    string n;
    if (!(cin >> n)) {
        return 1;
    }
    string m;
    cin >> m;
    for (int i = 0; i < sz(n) + 1; ++i) {
        dp[i][0] = i;
    }
    for (int i = 0; i < sz(m) + 1; ++i) {
        dp[0][i] = i;
    }
    for (int i = 1; i < sz(n) + 1; ++i) {
        for (int j = 1; j < sz(m) + 1; ++j) {
            if (n[i - 1] != m[j - 1]) {
                dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
            } else {
                dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1]));
            }
        }
    }
    cout << dp[sz(n)][sz(m)] << endl;
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
