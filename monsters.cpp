// : https://cses.fi/problemset/task/1194
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
const int N = 1e3 + 1;
const int M = 1e3 + 1;
char dir[] = {'R','D','L','U'};

bool check(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}
int solve() {
    cin>> n >> m;
    vector<int> g[N];
    vector<int> da[N];
    vector<int> dm[N];
    vector<int> pr[N];
    vector<int> used[N];
    pair<int,int> source;
    for (ll i = 0; i < n; i++) {
        string t; cin >> t;
        d(t);
        g[i].resize(M);
        da[i].resize(M);
        dm[i].resize(M);
        used[i].resize(M);
        pr[i].resize(M);
        for (ll j = 0; j < m; j++) {
            da[i][j] = -1;
            used[i][j] = 0;
            g[i][j] = 0;
            if (t[j] == '#') {
                g[i][j] = 1;
            }
            else if(t[j] == 'A') {
                g[i][j] = 2;
                source = {i,j};
            }
            else if(t[j] == 'M') g[i][j] = 3;
        }
    }
    function <void (queue<pair<int,int>>) > bfs1 = [&](queue<pair<int,int>> q) {
        while(!q.empty()) {
            auto v = q.front(); q.pop();
            for (ll i = 0; i < 4; i++) {
                if (check(v.first + dx[i],v.second + dy[i]) && g[v.first + dx[i]][v.second + dy[i]] != 1 && used[v.first + dx[i]][v.second + dy[i]] == 0) {
                    used[v.first + dx[i]][v.second + dy[i]] = 1;
                    q. push({v.first + dx[i],v.second + dy[i]});
                    pr[v.first + dx[i]][v.second + dy[i]] = dir[i];
                    if (v.first + dx[i] == 3 && v.second + dy[i] == 7) {
                        d(v);
                    }
                    da[v.first + dx[i]][v.second + dy[i]] = da[v.first][v.second] + 1;
                }
            }
        }
    };
    function <void (queue<pair<int,int>>) > bfs2 = [&](queue<pair<int,int>> q) {
        while(!q.empty()) {
            auto v = q.front(); q.pop();
            for (ll i = 0; i < 4; i++) {
                if (check(v.first + dx[i],v.second + dy[i]) && g[v.first + dx[i]][v.second + dy[i]] != 1 && used[v.first + dx[i]][v.second + dy[i]] == 0) {
                    used[v.first + dx[i]][v.second + dy[i]] = 1;
                    q. push({v.first + dx[i],v.second + dy[i]});
                    dm[v.first + dx[i]][v.second + dy[i]] = dm[v.first][v.second] + 1;
                }
            }
        }
    };

    used[source.first][source.second] = 1;
    da[source.first][source.second] = 0;
    queue<pair<int,int>> q; q.push(source);
    bfs1(q);
    while(!q.empty()) q.pop();
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            used[i][j] = 0;
            dm[i][j] = -1;
        }
    }
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if (g[i][j] == 3) {
                dm[i][j] = 0;
                used[i][j] = 1;
                d(i,j);
                q. push({i,j});
            }
        }
    }
    bfs2(q);
    int curi= -1; int curj =-1;
    for(int i : {0,n-1}){
        for (int j = 0; j < m; j++) {
            if (da[i][j] != -1 && (da[i][j] < dm[i][j] || dm[i][j] == -1)) {
                curi = i;
                curj = j;
                break;
            }
        }
    }
    for (ll i = 0; i < n; i++) {
        for(auto j : {0,m-1} ) {
            if (da[i][j] != -1 && (da[i][j] < dm[i][j] || dm[i][j] == -1)) {
                curi = i;
                curj = j;
                break;
            }
        }
    }
    if (curi == -1 && curj == -1) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    vector<char> a;
    while(g[curi][curj] != 2) {
        d(curi,curj);
        a. push_back(pr[curi][curj]);
        for (ll i = 0; i < 4; i++) {
            if (dir[i] == pr[curi][curj]) {
                curi -= dx[i];
                curj -= dy[i];
                break;
            }
        }
    }
    cout << sz(a) << endl;
    reverse( a.begin(), a.end());
    for_each( a.begin(), a.end(), [](char x) {cout << x ;});
    cout << endl;
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
