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
int solve()
{
    int n;
    if (!(cin >> n)) {
        return 1;
    }
    vector<int> arr(n);
    for (int& val : arr) {
        cin >> val;
    }
    vector<ll> psum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        psum[i + 1] = psum[i] + arr[i];
    }
    vector<vector<ll>> dp(5000 + 1, vector<ll>(5000 + 1, 0));
    for (int i = n; i > 0; i--) {
        dp[i][i] = arr[i - 1];
        for (int j = i + 1; j < n + 1; j++) {
            dp[i][j] = max((psum[j] - psum[i - 1]) - dp[i][j - 1], (psum[j] - psum[i - 1]) - dp[i + 1][j]);
        }
    }
    cout << dp[1][n] << endl;
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
