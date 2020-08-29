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
    int h, w, m;
    cin >> h >> w >> m;
    vint h_count(h, 0), w_count(w,0);
    vector<vint> field(h, vint(w, 0));
    rep(i,m){
        int y, x;
        cin >> y >> x;
        y--; x--;
        field[y][x] = 1;
        h_count[y]++;
        w_count[x]++;
    }
    int h_count_max=0, w_count_max=0;
    rep(i,h){
        h_count_max = max(h_count_max, h_count[i]);
    }
    rep(i,w){
        w_count_max = max(w_count_max, w_count[i]);
    }

    vint h_max_list, w_max_list;
    rep(i,h){
        if(h_count[i] == h_count_max) h_max_list.pb(i);
    }
    rep(i,w){
        if(w_count[i] == w_count_max) w_max_list.pb(i);
    }

    int flag = 0;
    rep(i, h_max_list.size()){
        rep(j, w_max_list.size()){
            printf("check y=%d, x=%d, field=%d\n", h_max_list[i], w_max_list[j], field[h_max_list[i]][w_max_list[j]]);
            if(field[h_max_list[i]][w_max_list[j]] == 0){
                flag = 1;
                goto end;
            }
        }
    }
    end:
        int ans = h_count_max + w_count_max - 1;
        cout << ans + flag << endl;
}

