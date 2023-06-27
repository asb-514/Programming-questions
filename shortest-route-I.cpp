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

const ll inf = 1e17;
int solve()
{
    int n;
    if (!(cin >> n)) {
        return 1;
    }
    int m;
    cin >> m;
    vector<vector<pair<ll, ll>>> g(n);
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        g[x].push_back({ y, z });
    }
    set<pair<ll, ll>> q;
    q.insert({ 0, 0 });
    dbg(q);
    vector<ll> d(n, inf);
    vector<ll> p(n, inf);
    d[0] = 0;
    p[0] = -1;
    auto dikstra = [&]() {
        while (!q.empty()) {
            ll dv = q.begin()->first;
            ll v = q.begin()->second;
            q.erase({ dv, v });
            for (auto u : g[v]) {
                ll to = u.first;
                ll dto = u.second;
                if (d[to] > d[v] + dto) {
                    q.erase({ d[to], to });
                    d[to] = d[v] + dto;
                    p[to] = v;
                    q.insert({ d[to], to });
                }
            }
        }
    };
    dikstra();
    for (int i = 0; i < n; i++) {
        cout << d[i] << " ";
    }
    cout << endl;
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
