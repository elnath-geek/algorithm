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
const ll inf = 1e18;
const ll mod = 1e9 + 7;



int main(){
    int n,m;
    cin >> n >> m;
    int a[110][110];
    rep(i,n) rep(j,m) cin >> a[i][j];

    ll ans=0;
    rep(i,m){
        for(int j=i+1; j<m; j++){
            ll tmp=0;
            rep(k,n){
                tmp += max(a[k][i], a[k][j]);
            }
            if(tmp > ans) ans = tmp;
        }
    }
    cout << ans << endl;
}
