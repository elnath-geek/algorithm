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

int d;
ll ans=0;
int c[26]; // 満足度の下がりやすさ、（d-最終日）* cだけその日の終わりに引かれる。

int s[365][26]; // d日目にタイプiのコンテストを開いた時の上昇量
int t[365];

ll solve(){
    ll tmp_ans=0;
    int day=1;
    vector<vint> last(26, vint(1, 0));
    int last_num[26] = {0};
    rep(i,26) last[i].pb(0);
    rep(i,d){
        tmp_ans += s[i][t[i]];
        last[t[i]].pb(day);
        last_num[t[i]]++;
        rep(j,26){
            tmp_ans -= c[j] * (day - last[j][last_num[j]]);
        }
        day++;
    }
    return tmp_ans;
}

int main(){
    cin >> d;
    rep(i, 26) cin >> c[i];
    rep(i,d){
        int max_s =0;
        rep(j,26){
            cin >> s[i][j];
            if(max_s < s[i][j]){
                max_s = s[i][j];
                // t[i] = j;
            }
        }
        t[i] = i;
    }
    // cout << start << endl;
    int count=0;
    while(count < 10000){
        count++;
        int md = rand()%365;
        int mq = rand()%26;
        int old = t[md];
        t[md] = mq;
        ll tmp_ans = solve();
        if(ans < tmp_ans){
            ans = tmp_ans;
        }else{
            t[md] = old;
        }
    }
    rep(i,d){
        cout << t[i]+1 << endl;
    }
    // cout << ans << endl;
}
