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
    int n, max_w;
    cin >> n >> max_w;
    vector<vint> dp(n+1, vint(max_w+1, 0));
    // dp[i][j] = v; において、i番目までの品物で、重さjいかにおいてvの価値を持つ。
    rep(i,n){
        int v, w;
        cin >> v >> w;
        rep(j, max_w+1){
            if(j < w){
                dp[i+1][j] = dp[i][j];
            }else{
                dp[i+1][j] = max(dp[i][j], dp[i][j-w] + v);
            }
        }
    }
    rep(i,n+1){
        rep(j,max_w+1){
            cout << dp[i][j] << " ";
        }
        cout <<endl;
    }
    cout << dp[n][max_w] << endl;
}
