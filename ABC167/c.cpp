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

int c[20];
int a[20][20] = {0};
int tmp[20] = {0};


int main(){
    int n, m, x;
    cin >> n >> m >> x;
    int ans=1e9;
    rep(i,n){
        cin >> c[i];
        rep(j,m) cin >> a[i][j];
    }
    for(int bit=0; bit<(1<<n); bit++){
        rep(i,m) tmp[i] = 0;
        // printf("bit = %d\n", bit);
        int tmp_ans=0;
        rep(i,n){
            if( (bit>>i) & 1){
                tmp_ans += c[i];
                rep(j,m){
                    tmp[j] += a[i][j];
                }
            }
        }
        bool flag = 1;
        rep(i,m){
            // cout << tmp[i] << " ";
            if(tmp[i] < x) flag=0;
        }
        // cout << endl;
        if(flag) ans = min(ans, tmp_ans);
    }
    if(ans == 1e9) ans = -1;
    cout << ans << endl;
}

