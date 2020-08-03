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

int main(){
    int n, m;
    cin >> n >> m;
    vint dp(n+1, 1e9);
    vint c(m);
    sort(all(c));
    rep(i,m){
        cin >> c[i];
    }
    dp[0] = 0;
    rep(i,n+1){
        rep(j,m){
            if(i >= c[j]) dp[i] = min(dp[i], dp[i-c[j]] + 1);
        }
        // printf("dp[%d] = %d\n", i, dp[i]);
    }
    cout << dp[n] << endl;
}
