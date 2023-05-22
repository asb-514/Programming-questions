#ifdef ONPC
    #define _GLIBCXX_DEBUG
    //#include "bits/stdc++.h"
    #include <bits/stdc++.h>
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
    #define d(...)
#else
    #define d(...)
#endif
int f(ll x, ll y) {
    ll ans = (x % y);
    if (ans < 0 ) {
        ans += y;
    }
    return ans;
}
int solve() {
    ll n;ll d;ll w;cin >> n >> w >> d;
    ll ans = 0;
    vector<ll> an(n);
    ll flag = 0;
    for (ll &val : an) {
        cin >> val;
    }
    for (ll j = 0; j < n/2; j++) {
        ll b = an[n-j-1];
        ll a  = an[j];
        ll curans = 1e15;
        if (a == b) {
            continue;
        }
        for (ll i = 1; i < d + 1; i++) {
            if ((i*w + b - a ) % d == 0) {
                curans = min(curans,(i*w + b - a ) / d);
            }
            if((i*w - b + a ) % d == 0) {
                curans = min(curans,(i*w - b + a ) / d);
            }
        }
        if (b-a >= 0 && (b - a) % d == 0) {
            curans = min(curans,(b-a)/d);
        }
        if (a - b >= 0 && (b - a) % d == 0) {
            curans = min(curans,(a-b)/d);
        }
        if (curans == 1e15) {
            flag = 1;
            break;
        }
        d(ans,curans);
        ans += curans;
    }
    if (flag) {
        cout << " IMPOSSIBLE" << endl;
        return 0;
    }
    else {
        cout << ans << endl;
    }
    return 0;
}

int32_t main() {
    //sieve(2e5+10);
    ios::sync_with_stdio(0); cin.tie(0); int TET = 1;
    for (int i = 1; i <= TET; i++) {
        cout << "Case #" << i << ":" << " ";
        if (solve()) {break;}
        #ifdef ONPC
            cout << "__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}

