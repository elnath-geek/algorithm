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
    int n;
    cin >> n;
    vint p(n);
    vint graph[n];
    rep(i,n){
        int to;
        cin >> to;
        p[i] = to-1;
        if(p[i] != -2){
            graph[i].pb(p[i]);
            graph[p[i]].pb(i);
        }
    }
    rep(i,n){
        sort(all(graph[i]));
        graph[i].erase(unique(all(graph[i])), graph[i].end() );
        // rep(j, graph[i].size()) cout << graph[i][j] << " "; cout << endl;
    }

    ll baseroad = 0;
    rep(i,n){
        baseroad += graph[i].size();
    }
    baseroad /= 2;
    // cout << "baseroad = " << baseroad << endl;

    ll k=0;
    ll unconnect = 0;
    rep(i,n){
        if(p[i] == -2){
            int connectnum = 0;
            k++;
            vint visit(n, 0);
            queue<int> q;
            q.push(i);
            visit[i] = 1;
            while(!q.empty()){
                int now = q.front(); q.pop();
                for(int next: graph[now]){
                    // printf("now = %d, next = %d\n", now, next);
                    if(visit[next] == 0){
                        connectnum++;
                        visit[next] = 1;
                        q.push(next);
                    }
                }
            }
            unconnect += n-1-connectnum;
            // cout << unconnect << endl;
        }
    }
    ll ans = baseroad * modpow(n-1, k) + unconnect * modpow(n, k-1);
    ans %= mod;
    cout << ans << endl;
}

