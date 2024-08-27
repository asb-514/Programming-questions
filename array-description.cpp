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

int solve()
{
    ll n;
    if (!(cin >> n)) {
        return 1;
    }
    ll m;
    cin >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<ll>> dp(n, vector<ll>(m + 1, -1));
    function<ll(ll, ll)> rec = [&](ll idx, ll val) {
        if (val > m) {
            return (ll)0;
        }
        if (val < 1) {
            return (ll)0;
        }
        if (a[idx] != 0) {
            if (a[idx] == val) {
                return (ll)1;
            } else
                return (ll)0;
        }
        if (idx == n - 1) {
            return (ll)1;
        }
        if (dp[idx][val] != -1) {
            return dp[idx][val];
        }
        return dp[idx][val] = (((rec(idx + 1, val)) + (rec(idx + 1, val + 1)) % (ll)(1e9 + 7)) + (rec(idx + 1, val - 1)) % (ll)(1e9 + 7));
    };
    int flag = 0;
    ll gans = 1;
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] != 0 && a[i - 1] != 0 && (abs(a[i] - a[i - 1]) > 1)) {
            gans = 0;
        }
    }
    dbg(gans);
    for (int i = 0; i < n; i++) {
        if (a[i] == 0 && flag == 0) {
            flag = 1;
            if (i != 0) {
                ans += rec(i, a[i - 1] + 1);
                ans %= (ll)1e9 + 7;
                ans += rec(i, a[i - 1] - 1);
                ans %= (ll)1e9 + 7;
                ans += rec(i, a[i - 1] + 0);
                ans %= (ll)1e9 + 7;
            } else {
                for (int j = 1; j <= m; j++) {
                    ans += rec(i, j);
                    ans %= (ll)1e9 + 7;
                }
            }
        } else if (a[i] != 0 && flag == 1) {
            flag = 0;
            gans *= ans;
            gans %= (ll)1e9 + 7;
            ans = 0;
        }
    }
    if (flag == 1) {
        flag = 0;
        gans *= ans;
        gans %= (ll)1e9 + 7;
        ans = 0;
    }
    cout << gans << endl;
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
