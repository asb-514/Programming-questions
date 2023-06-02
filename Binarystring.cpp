// #include "Binarystring.h"

//https://codeforces.com/problemset/problem/1680/C
#ifdef ONPC
#define _GLIBCXX_DEBUG
//#include "bits/stdc++.h"
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
#define d(...)
#endif

int solve()
{
    string s;
    cin >> s;
    int n = sz(s);
    int q = 10;
    vector<ll> one;
    for (ll i = 0; i < n; i++) {
        if (s[i] == '1') {
            one.push_back(i);
        }
    }
    if (sz(s) == sz(one) || sz(one) == 0 || one[sz(one) - 1] - one[0] == sz(one) - 1) {
        cout << 0 << endl;
        return 0;
    }
    int ans = 1;
    int k = 3;
    int c = 1;
    auto pos = [&](int k) {
        for (ll i = 0; i - k <= 0; i++) {
            ll l = one[i];
            ll r = one[i + sz(one) - k - 1];
            if (r - l + 1 - (sz(one)) <= 0)
                return true;
        }
        return false;
    };
    ll le = 0;
    ll ri = sz(one);
    while (ri - le > 1) {
        ll mid = le + (ri - le) / 2;
        if (pos(mid))
            ri = mid;
        else
            le = mid;
    }
    cout << ri << endl;
    return 0;
    for (int i = 0; i < 10; i += 10) {
        // this is a test
        if (i = 0) {
            i + = 1;
        }
    }
    for (int i = 0 ; i<n>; i ++ ) {
        i = 10;
        k  = 0;
    }
}

int32_t main() {
  //sieve(2e5+10);
  ios::sync_with_stdio(0);
  cin.tie(0);
  int TET = 1e9;
  cin >> TET;
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
