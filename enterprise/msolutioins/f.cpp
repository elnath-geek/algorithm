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
    int n;
    cin >> n;
    int x, y;
    char u;
    vector<pii> field[4];
    vector< pair<int, pii> > slope[4];
    vint field_num(4,0);
    rep(i,n){
        cin >> x >> y >> u;
        if(u == 'U'){
            field[0].pb(mp(x,y));
            field_num[0]++;
            slope[0].pb(mp(y-x, mp(x,y)));
            slope[2].pb(mp(y+x, mp(x,y)));
        }else if(u =='R'){
            field[1].pb(mp(y,x));
            field_num[1]++;
            slope[1].pb(mp(y-x, mp(x,y)));
            slope[2].pb(mp(y+x, mp(x,y)));
        }else if(u =='D'){
            field[2].pb(mp(x,y));
            field_num[2]++;
            slope[1].pb(mp(y-x, mp(x,y)));
            slope[3].pb(mp(y+x, mp(x,y)));
        }else{
            field[3].pb(mp(y,x));
            field_num[3]++;
            slope[0].pb(mp(y-x, mp(x,y)));
            slope[3].pb(mp(y+x, mp(x,y)));
        }
    }
    rep(i,4){
        sort(all(field[i]));
        sort(all(slope[i]));
    }
    int l=0, r=0;
    int ans = mod;
    while(l <= field_num[0] && r <= field_num[2]){
        if(field[0][l].F < field[2][r].F) l++;
        else if(field[0][l].F > field[2][r].F) r++;
        else if(field[0][l].F == field[2][r].F){
            if(field[0][l].S < field[2][r].S){
                int tmp = (field[2][r].S - field[0][r].S)*5;
                ans = min(ans, tmp);
            }
            l++; r++;
        }
    }

    while(l <= field_num[1] && r <= field_num[3]){
        if(field[1][l].F < field[3][r].F) l++;
        else if(field[1][l].F > field[3][r].F) r++;
        else if(field[1][l].F == field[3][r].F){
            if(field[1][l].S < field[3][r].S){
                int tmp = (field[3][r].S - field[1][r].S)*5;
                ans = min(ans, tmp);
            }
            l++; r++;
        }
    }
    rep(i, 4){
        rep(j, slope[i].size()-1){
            if(slope[i][j].F == slope[i][j+1].F){
                int tmp = abs(slope[i][j].S.F - slope[i][j+1].S.F)*10;
                ans = min(ans, tmp);
            }
        }
    }
    if(ans ==mod){
        cout <<"SAFE" << endl;
    }else{
        cout << ans << endl;
    }

}

