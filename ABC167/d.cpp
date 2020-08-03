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

int main(){
    ll n, k;
    cin >> n >> k;
    vll a(n);
    rep(i,n){
        ll tmp;
        cin >> tmp;
        a[i] = tmp-1;
    }
    vll visit(n,0);
    vll town_array(n,0);
    ll now = 0;
    ll count = 0;

    while(1){
        if(visit[now] == 2) break;
        visit[now] +=  1;
        if(visit[now] == 1) town_array[count] = now;
        count++;
        now = a[now];
    }
    ll c1 = 0, c2 = 0;
    rep(i,n){
        // cout << town_array[i] << " ";
        if(visit[i] == 1) c1++;
        if(visit[i] == 2) c2++;
    }
    // printf("c1 = %lld, c2 = %lld\n", c1, c2);
    ll ans = 1;
    if(c1 > k){
        ans += town_array[k];
    }else{
        k -= c1;
        k %= c2;
        ans += town_array[c1 + k];
    }
    cout << ans << endl;
}

