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
    int h,w;
    cin >> h >> w;
    int ch, cw, dh, dw;
    cin >> ch >> cw >> dh >> dw;
    ch--, cw--, dh--, dw--;
    vector<vector<char>> s(h, vector<char>(w));
    rep(i,h) rep(j,w) cin >> s[i][j];
    vector<vint> visit(h, vint(w, -1));

    queue<pii> q;
    queue<pii> edge_q;
    q.push(mp(ch,cw));
    int warp = 0;
    visit[ch][cw] = warp;
    while(!q.empty() || !edge_q.empty()){
        while(!q.empty()){
            pii pos = q.front(); q.pop();
            rep(i,4){
                int ny = pos.F + dy[i];
                int nx = pos.S + dx[i];
                if( 0<=nx && nx<w && 0<=ny && ny<h && s[ny][nx] == '.'){
                    if(visit[ny][nx] == -1){
                        visit[ny][nx] = warp;
                        q.push(mp(ny, nx));
                    }
                }
                if( 0<=nx && nx<w && 0<=ny && ny<h && s[ny][nx] == '#'){
                    edge_q.push(pos);
                }
            }
        }
        warp++;
        while(!edge_q.empty()){
            pii pos = edge_q.front(); edge_q.pop();
            rep(i, 5){
                rep(j,5){
                    int ny = pos.F + i -2;
                    int nx = pos.S + j -2;
                    if( 0<=nx && nx<w && 0<=ny && ny<h && s[ny][nx] == '.'){
                        if(visit[ny][nx] == -1){
                            visit[ny][nx] = warp;
                            q.push(mp(ny, nx));
                        }
                    }
                }
            }
        }
    }
    cout << visit[dh][dw] << endl;
}

