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
const int N = 1e6 + 2;
vector<ll> tot(N, 0);
vector<ll> lvb(N, 0);
int solve()
{
    int n;
    cin >> n;
    cout << tot[n] << endl;
    return 0;
}

int32_t main()
{
    // sieve(2e5+10);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1e9;
    cin >> TET;
    tot[1] = 2;
    lvb[1] = 1;
    for (int i = 2; i <= N - 1; i++) {
        tot[i] = 3 * tot[i - 1];
        tot[i] %= mod;
        tot[i] += 2 * lvb[i - 1];
        tot[i] %= mod;

        lvb[i] = 3 * lvb[i - 1];
        lvb[i] %= mod;
        lvb[i] += tot[i - 1];
        lvb[i] %= mod;
    }

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
