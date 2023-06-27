#ifdef ONPC
#define _GLIBCXX_DEBUG
#include <algorithm>
#include <array>
#include <atomic>
#include <bitset>
#include <chrono>
#include <climits>
#include <complex>
#include <condition_variable>
#include <deque>
#include <exception>
#include <forward_list>
#include <fstream>
#include <functional>
#include <future>
#include <initializer_list>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <mutex>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <system_error>
#include <thread>
#include <tuple>
#include <type_traits>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>
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
const ll mod = 1e9 + 7;
int solve()
{
    int n;
    if (!(cin >> n)) {
        return 1;
    }
    int m;
    cin >> m;
    vector<vector<ll>> dp(n, vector<ll>(m + 1, 0));
    vector<ll> a(n);
    for (ll& val : a) {
        cin >> val;
    }
    if (a[0] == 0) {
        for (int i = 1; i < m + 1; i++) {
            dp[0][i] = 1;
        }
    } else
        dp[0][a[0]] = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] == 0) {
            for (int j = 1; j < m + 1; j++) {
                for (auto k : { j - 1, j, j + 1 }) {
                    if (k <= m && k >= 1)
                        dp[i][j] += dp[i - 1][k];
                    dp[i][j] %= mod;
                }
            }
        } else {
            for (auto k : { a[i] - 1, a[i], a[i] + 1 }) {
                if (k <= m && k >= 1)
                    dp[i][a[i]] += dp[i - 1][k];
                dp[i][a[i]] %= mod;
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i < m + 1; i++) {
        ans += (dp[n - 1][i]);
        ans %= mod;
    }
    cout << ans << endl;
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
#ifdef ONPC
        cout << "__________________________" << endl;
#endif
    }
#ifdef ONPC
    cerr << endl
         << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
