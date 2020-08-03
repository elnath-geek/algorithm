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

int dp[1010][1010] = {0};

int lcs(string x, string y){
    int n = x.size();
    int m = y.size();
    int ans = 0;
    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            if(y[j-1] == x[i-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            ans = max(ans, dp[i][j]);
        }
    }
    rep(i, n+1){
        rep(j, m+1) cout << dp[i][j] << " ";
        cout << endl;
    }
    return ans;

}

int main(){
    int q;
    cin >> q;
    rep(i, q){
        string x,y;
        cin >> x >> y;
        cout << lcs(x,y) << endl;
    }
}
