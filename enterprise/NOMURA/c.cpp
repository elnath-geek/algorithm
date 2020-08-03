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

ll a[100010];
ll maxroot[100010] = {0};

int main(){
    int n;
    cin >> n;
    // vll a(n+1);
    // vll maxroot(n+1, 0);
    rep(i,n+1){
        cin >> a[i];
        if(i == 0){
            maxroot[i] = 1 - a[i];
        }else{
            maxroot[i] = maxroot[i-1]*2 - a[i];
        }
        if(maxroot[i] > inf){
            maxroot[i] = inf;
        }
        if(maxroot[i] < 0){
            cout << -1 << endl;
            return 0;
        }
        // cout << maxroot[i] << endl;
    }
    ll ans = 0;
    ll tmp = 0;
    for(int i=n; i>=0; i--){
        if(tmp > maxroot[i]){
            tmp = maxroot[i];
        }
        tmp += a[i];
        ans += tmp;
        // cout << tmp << endl;
    }
    cout << ans << endl;

}

