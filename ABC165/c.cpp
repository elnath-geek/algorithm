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

int query[60][5];
int n, m, q, ans=0;
int a[11] = {0};

void dfs(int index, int lastnum){
    a[index] = lastnum;
    if(index == n-1){
        int tmp=0;
        rep(i,q){
            if(a[query[i][1]] - a[query[i][0]] == query[i][2]) tmp += query[i][3];
        }
        // rep(i,n) cout << a[i] << " ";
        // cout << "tmp = " << tmp << endl;
        ans = max(ans, tmp);
    }else{
        for(int i=lastnum; i<=m; i++){
            dfs(index+1, i);
        }
    }
}

int main(){
    cin >> n >> m >> q;
    rep(i,q){
        int a, b;
        cin >> a >> b >> query[i][2] >> query[i][3];
        query[i][0] = a-1;
        query[i][1] = b-1;
    }
    dfs(0, 1);
    cout << ans << endl;
}

