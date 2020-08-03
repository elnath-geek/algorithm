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
    int n,k;
    cin >> n >> k;
    vll a(n);
    rep(i,n) cin >> a[i];
    sort(all(a));
    int l=0, r = n-1;
    int count = k;
    ll ans=1;
    if(a[n-1] < 0 && k%2==1){
        rep(i,k){
            ans *= a[n-i-1];
            ans %= mod;
        }
    }else{
        while(1){
            if(count == 1){
                ans *= a[r];
                ans %= mod;
                break;
            }
            ld ltmp=1, rtmp=1;
            ltmp *= a[l]; ltmp *= a[l+1];
            rtmp *= a[r]; rtmp *= a[r-1];
            if(ltmp <= rtmp){
                ans *= a[r];
                ans %= mod;
                r -= 1;
                count -= 1;
            }else{
                ans *= a[l];
                ans %= mod;
                ans *= a[l+1];
                ans %= mod;
                l += 2;
                count -= 2;
            }
            if(count == 0) break;
        }
    }

    if(ans < 0) ans += mod;
    cout << ans << endl;
}

