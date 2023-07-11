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
    vector<int> pos(1e5 + 2, 0);
    int n;
    if (!(cin >> n)) {
        return 1;
    }
    vector<int> a(n);
    for (int& val : a) {
        cin >> val;
    }
    dbg(a);
    pos[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 1e5 + 1; j > -1; j--) {
            if (pos[j] == 1 && (a[i] + j <= sz(pos) - 1)) {
                pos[a[i] + j] = 1;
            }
        }
    }
    int cnt = 0;
    for (int j = 0; j < 1e5 + 1; j++) {
        if (pos[j] == 1 && j != 0)
            cnt++;
    }
    cout << cnt << endl;
    for (int j = 0; j < 1e5 + 1; j++) {
        if (pos[j] == 1 && j != 0)
            cout << j << " ";
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
