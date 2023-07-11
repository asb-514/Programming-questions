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
    vector<int> a(n);
    for (int& val : a) {
        cin >> val;
    }
    const ll inf = 1e14;
    vector<ll> dp(n + 3, inf);
    dp[0] = -inf;
    for (int i = 0; i < n; i++) {
        auto idx = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        if (a[i] > dp[idx - 1] && a[i] < dp[idx]) {
            dp[idx] = a[i];
        }
    }
    int cnt = 0;
    for (int i = 0; i < sz(dp); ++i) {
        if (dp[i] != inf)
            cnt++;
    }
    cout << cnt - 1 << endl;
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
