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
    ll n;
    cin >> n;
    vint a(n);
    rep(i,n) cin >> a[i];
    vector<vll> dp(n+1, vll(21, 0));
    dp[0][a[0]] = 1;
    for(int i=1; i<n; i++){
        rep(val, 21){
            if(val-a[i] < 0) dp[i+1][val] = dp[i][val+a[i]];
            else if(val+a[i] > 20) dp[i+1][val] = dp[i][val-a[i]];
            else dp[i+1][val] = dp[i][val-a[i]] + dp[i][val+a[i]];
        }
    }
    // rep(i,n+1){
    //     rep(val, 21) cout << dp[i][val] << " ";
    //     cout << endl;
    // }
    cout << dp[n][0] << endl;
}
