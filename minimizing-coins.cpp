// #include "minimizing-coins.h"

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
    // similar to bfs so can use a approach similar to bfs also
    int n;
    cin >> n;
    int target_sum;
    cin >> target_sum;
    vector<ll> a(n); // set of coins
    for (ll& val : a) {
        cin >> val;
    }

    vector<ll> dp(target_sum + 10, 1e18);
    dp[0] = 0;
    for (int i = 0; i < target_sum; i++) {
        for (int j = 0; j < n; j++) {
            if (i + a[j] <= target_sum && dp[i + a[j]] > dp[i] + 1) {
                dp[i + a[j]] = dp[i] + 1;
            }
        }
    }
    if (dp[target_sum] == 1e18) {
        cout << -1 << endl;
    } else {
        cout << dp[target_sum] << endl;
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
