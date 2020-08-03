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
#include <bit>
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

// mod.m での a の逆元 a^(-1) を計算する。
ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while(b){
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
    int n;
    string x_str;
    cin >> n >> x_str;
    int oc=0;
    vector<vint> rem(2, vint(n,1));
    rep(i, n){
        if(x_str[i] == '1') oc++;
    }
    if(oc==0){
        rep(i,n) cout << 1 << endl;
        return 0;
    }

    for(int i=n-2; i>=0; i--){
        if(oc==1){
            rem[0][i] = 0;
            rem[0][i+1]=0;
        }else{
            rem[0][i] = 2*rem[0][i+1];
            rem[0][i] %= oc-1;
        }
        rem[1][i] = 2*rem[1][i+1];
        rem[1][i] %= oc+1;
    }
    int rem_sm=0, rem_sp=0;
    rep(i,n){
        if(x_str[i] == '1'){
            rem_sm += rem[0][i];
            rem_sm %= oc-1;
            rem_sp = rem[1][i];
            rem_sp %= oc+1;
        }
    }
    vint next(n);
    vint ans(n,1);
    rep(i,n){
        if(x_str[i]=='1'){
            next[i] = rem_sm - rem[0][i];
            if(next[i]<0) next[i] += oc-1;
        }else{
            next[i] = rem_sp + rem[1][i];
            next[i] %= oc+1;
        }
    }
    vint popnext(n,0);
    for(int i=1; i<n; i++){
        popnext[i] = i % __builtin_popcount(i);
    }
    rep(i,n){
        while(next[i]>0){
            next[i] = popnext[next[i]];
            ans[i]++;
        }
    }
    rep(i,n){
        cout << ans[i] << endl;
    }
}




