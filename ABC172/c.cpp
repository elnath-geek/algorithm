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
    ll n, m, k;
    cin >> n >> m >> k;
    vll a(n);
    vll b(m);
    rep(i,n){
        int tmp;
        cin >> tmp;
        if(i ==0) a[i] = tmp;
        else a[i] = a[i-1] + tmp;
        if(a[i] > inf){
            a[i] = inf;
        }
        // cout << a[i] << " ";
    }
        // cout << endl;
    rep(i,m){
        int tmp;
        cin >> tmp;
        if(i ==0) b[i] = tmp;
        else b[i] = b[i-1] + tmp;
        if(b[i] > inf){
            b[i] = inf;
        }
        // cout << b[i] << " ";
    }
        // cout << endl;

    int ans = 0;
    rep(i,n+1){ // aでi本読む時を考える
        int rem = 0;
        int flag = 0;
        if(i != 0 && a[i-1] <= k){
            rem = k - a[i-1];
            flag = 1;
        }else if(i == 0){
            flag = 1;
            rem = k;
        }
        auto it = upper_bound(all(b), rem);
        int tmp = it - b.begin();
        // printf("i = %d, rem = %d, it = %d\n", i, rem, it - b.begin());
        if(flag) ans = max(ans,  i + tmp);
    }
    cout << ans << endl;
}
