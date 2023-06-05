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
    auto digits = [&](int k) {
        vector<int> dig;
        while (k != 0) {
            dig.push_back(k % 10);
            k /= 10;
        }
        return dig;
    };
    vector<ll> dp(n + 1, 1e18);
    dp[0] = 0;
    for (int i = 1; i < n + 1; i++) {
        vector<int> t = digits(i);
        for (auto d : t) {
            dp[i] = min(dp[i], dp[i - d] + 1);
        }
    }
    cout << dp[n] << endl;
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
