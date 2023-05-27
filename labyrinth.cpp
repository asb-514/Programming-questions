// : https://cses.fi/problemset/task/1193
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
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int n, m; // DON'T MAKE THEM IN MAIN
const int N = 1e3 + 2;
const int M = 1e3 + 2;
int g[N][M];

bool check(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && g[x][y] != 1;
}
int solve() {
    cin >> n >> m;
    int sn = 0;int sm = 0;
    int fn = 0; int fm = 0;
    for (ll i = 0; i < n; i++) {
        string t; cin >> t;
        for (ll j = 0; j < m; j++) {
            if ((int)t[j] == (int)'#') {
                g[i][j] = 1;
            }
            else if ((int)t[j] ==(int)'.') {
                g[i][j] = 0;
            }
            else if ((int)t[j] == (int)'A') {
                g[i][j] = -1;
                sn = i;sm = j;
            }
            else {
                g[i][j] = -2;
                fn = i; fm  = j;
            }
        }
    }
    vector<char> ans;
    function <void(int,int)> r = [&](int ssn,int ssm) {
        queue<pair<int,int>> q;
        q. push({ssn,ssm});
        int dis[n][m];
        pair<int,int> p[n][m];
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                dis[i][j] = 0;
                p[i][j] = {-1,-1};
            }
        }
        while(!q.empty()) {
            auto v = q.front();q.pop();
            g[v.first][v.second] = 1;
            ssn = v.first;
            ssm = v.second;
            for(auto x : dx) {
                if (check(ssn + x,ssm)) {
                    q. push({ssn+ x,ssm});
                    g[ssn+x][ssm] = 1;
                    p[ssn + x][ssm] = v;
                    dis[ssn+x][ssm] =  dis[p[ssn + x][ssm].first][p[ssn + x][ssm].second] + 1;
                }
            }
            for(auto y : dy) {
                if (check(ssn,ssm + y)) {
                    q. push({ssn,ssm+y});
                    g[ssn][ssm + y] = 1;
                    p[ssn][ssm + y] = v;
                    dis[ssn][ssm + y] = dis[p[ssn][ssm + y].first][p[ssn][ssm+y].second] + 1;
                }
            }
        }
        if (dis[fn][fm] == 0) {
            cout << "NO\n";
            return;
        }
        cout << "YES\n";
        pair<int,int> cur = {fn,fm};
        while(cur != make_pair(sn,sm) ) {
            auto par = p[cur.first][cur.second];
            char mv;
            if (par.first== cur.first) {
                if (par.second + 1 == cur.second) {
                    mv = 'R';
                }
                else mv = 'L';
            }
            else {
                if (par.first + 1 == cur.first) {
                    mv = 'D';
                }
                else mv = 'U';
            }
            ans. push_back(mv);
            cur = par;
        }
        reverse( ans.begin(), ans.end());
        cout << sz(ans) <<endl;
        for (ll i = 0; i < sz(ans); i++) {
            cout << ans[i];
        }
        cout << endl;
        return ;
    };
    r(sn,sm);
    return 0;
}

int32_t main() {
    //sieve(2e5+10);
    ios::sync_with_stdio(0); cin.tie(0); int TET = 1;
    for (int i = 1; i <= TET; i++) {
        if (solve()) {break;}
        #ifdef ONPC
            cout << "__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}
