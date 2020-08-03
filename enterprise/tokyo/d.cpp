#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <utility>
#include <complex>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <tuple>
#include <bitset>
#include <limits>
#include <algorithm>
#include <array>
#include <random>
#include <complex>
#include <regex>
#include <iomanip>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define fcout cout << fixed << setprecision(10)
#define rep(i,n)    for(int i=0; i<(int)n; i++)
#define mp(a,b) make_pair(a,b)
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second
const ll inf = 1e18;
const ll mod = 1e9 + 7;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

// mod. m での a の逆元 a^(-1) を計算する。
ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

ll modpow(ll a, ll n){
    ll res = 1;
    while(n>0){
        if(n&1){
            res = res * a % mod;
        }
        a = a * a % mod;
        n >>=1;
    }
    return res;
}




int main(){
    int n, q;
    int v, w;
    cin >> n;
    vint V(n);
    vint W(n);
    vector<pii> dp[n];
    rep(i,n){
        cin >> V[i] >> W[i];
        if(i > 0){
            rep(j, dp[(i-1)/2].size()){
                dp[i].pb(dp[(i-1)/2][j]);
                pii tmp = dp[(i-1)/2][j];
                dp[i].pb( mp(tmp.F + V[i], tmp.S + W[i]) );
            }
        }
        dp[i].pb(mp(V[i], W[i]));
    }

    // rep(i,n){
    //     rep(j, dp[i].size()){
    //         printf("%d %d \t", dp[i][j].F, dp[i][j].S);
    //     }
    //     cout << endl;
    // }

    cin >> q;
    rep(i,q){
        cin >> v >> w ;
        int ans=0;
        pii item;
        rep(j, dp[v-1].size()){
            item = dp[v-1][j];
            if(item.S <= w){
                ans = max(ans, item.F);
            }
        }
        cout << ans << endl;
    }
}

