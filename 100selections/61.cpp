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
#define rep(i,n)    for(int i=0; i<(ll)n; i++)
#define mp(a,b) make_pair(a,b)
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second
const ll inf = 1e18;
const ll mod = 1e9 + 7;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};



int main(){
    int n, m;
    cin >> n >> m;
    vector<vint> d(n, vint(n,1000000));
    rep(i,n) d[i][i] = 0;
    rep(i,m){
        int a, b, t;
        cin >> a >> b >> t;
        a--; b--;
        d[a][b] = t;
        d[b][a] = t;
    }
    rep(k,n){
        rep(i,n){
            rep(j,n){
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }
    int ans=1000000;
    rep(i,n){
        int tmp_ans=0;
        rep(j,n){
            tmp_ans = max(tmp_ans, d[i][j]);
            // cout << d[i][j] << " ";
        }
        // cout<< endl;
        ans = min(ans, tmp_ans);
    }
    cout << ans << endl;
}
