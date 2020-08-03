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
    int n, m;
    cin >> n >> m;
    vint edge[n];
    vint from(n, -1);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--; b--;
        edge[a].pb(b);
        edge[b].pb(a);
    }
    queue<int> q;
    q.push(0);
    from[0] = 0;
    while(!q.empty()){
        int pos = q.front(); q.pop();
        for(int to : edge[pos]){
            if(from[to] == -1){
                from[to] = pos;
                q.push(to);
            }
        }
    }
    int flag=1;
    rep(i,n) if(from[n] == -1) flag=0;
    if(flag){
        cout << "Yes" << endl;
        for(int i=1; i<n; i++) cout << from[i]+1 << endl;
    }
}

