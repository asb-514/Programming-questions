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
const int N = 412345;

vector<pair<ll, ll>> g[N];
int used[N];

int solve()
{
    int n;
    if (!(cin >> n)) {
        return 1;
    }
    for (int i = 0; i < 2 * n + 10; i++) {
        used[i] = 0;
        g[i].clear();
    }
    vector<vector<ll>> data(n, vector<ll>(3, 0));
    map<ll, ll> m;
    for (int i = 0; i < n; i++) {
        cin >> data[i][0];
        cin >> data[i][1];
        cin >> data[i][2];
        m[data[i][0]]++;
        m[data[i][1]]++;
    }
    ll cnt = 0;
    map<ll, ll> im;
    for (auto it = m.begin(); it != m.end(); it++) {
        im[cnt] += (it->first);
        it->second = cnt++;
    }
    for (int i = 0; i < n; i++) {
        g[m[data[i][0]]].push_back({ m[data[i][1]] + 1, -data[i][2] });
    }

    set<pair<ll, ll>> q;
    q.insert({ 0, 0 });
    vector<ll> dis(cnt + 3, 1e17); // todo
    dis[0] = 0;
    ll mi = 0;
    while (!q.empty()) {
        pair<ll, ll> pres = *q.begin();
        q.erase(q.begin());
        if (pres.second + 1 <= cnt)
            q.insert({ pres.first, pres.second + 1 });
        dis[pres.second] = min(dis[pres.second], pres.first);
        for (auto u : g[pres.second]) {
            ll to = u.first;
            ll from = pres.second;
            ll distance = u.second;
            if (dis[to] > dis[from] + distance) {
                q.erase({ dis[to], to });
                dis[to] = dis[from] + distance;
                q.insert({ dis[to], to });
            }
        }
    }
    for (int i = 0; i < sz(dis); i++) {
        mi = min(mi, dis[i]);
    }

    cout << -mi << endl;
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
