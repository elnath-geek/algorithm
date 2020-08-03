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
    vint a(n);
    rep(i,n){
        cin >> a[i];
    }
    rep(i,k){
        vint b(n+1, 0);
        int flag = 1;
        rep(i,n){
            int l = i - a[i];
            int r = i + a[i];
            if(l < 0) l = 0;
            if(r >= n) r = n-1;
            b[l]++;
            b[r+1]--;
        }
        int tmp=0;
        rep(i,n){
            tmp += b[i];
            a[i] = tmp;
            // cout << a[i] << " ";
            if(a[i] != n) flag = 0;
        }
        // cout << endl;
        if(flag) break;
    }
    rep(i,n) cout << a[i] << " "; cout << endl;
}

