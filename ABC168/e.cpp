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

const int MAX_N= 200000;
ll fac[MAX_N], finv[MAX_N], inv[MAX_N];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX_N; i++){
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = mod - inv[mod%i] * (mod / i) % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}

ll COM(int n, int k){
    if(n<k) return 0;
    if(n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n-k] % mod) % mod;
}

ll gcd(ll a, ll b){
    if(a%b == 0){
        return b;
    }else{
        return gcd(b, a%b);
    }
}

int main(){
    int n;
    cin >> n;
    vector<ld> p_list;
    vector<ld> m_list;
    rep(i,n){
        ld a, b;
        cin >> a >> b;
        ld tmp = a/b;
        if(tmp > 0) p_list.pb(tmp);
        else m_list.pb(tmp);
    }

    ll out_pair = 0;

    // rep(i, p_list.size()) cout << p_list[i] << " "; cout << endl;
    // rep(i, m_list.size()) cout << m_list[i] << " "; cout << endl;

    rep(i, m_list.size()){
        ld s_num = -1/m_list[i];
        int l_idx = lower_bound(all(p_list), s_num) - p_list.begin();
        int u_idx = upper_bound(all(p_list), s_num) - p_list.begin();
        out_pair += u_idx - l_idx;
    }
    // cout << "out_pair = " << out_pair << endl;
    ll ans = 0;
    for(int i=1; i<=n; i++){
        ans +=
    }

}

