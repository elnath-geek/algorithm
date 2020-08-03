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

int dp[110][10] = {0};

int main(){
    int n,k;
    cin >> n >> k;
    vint pasta(n+1, 3);
    rep(i,k){
        int a, b;
        cin >> a >> b;
        pasta[a] = b-1;
    }
    if(pasta[1] == 3 && pasta[2] == 3){
        rep(i,9) dp[2][i] = i;
    }else{
        if(pasta[1] != 3 && pasta[2] == 3){
            for(int i=pasta[1]*3; i<pasta[1]*3+3; i++){
                dp[2][i] = 1;
            }
        }else if(pasta[1] == 3 && pasta[2] != 3){
            rep(i,9){
                if(i%3 == pasta[2]) dp[2][i] = 1;
            }
        }else{
            dp[2][pasta[1]*3 + pasta[2]] = 1;
        }
    }
    for(int i=3; i<=n; i++){
        if(pasta[i] == 3){
            rep(pasta, 3){
                rep(j, 9){
                    if(j%3 == pasta){
                        rep(k,9){
                            if(j/3 == k%3 && j != k) dp[i][j] += dp[i-1][j];
                        }
                    }
                }
            }
        }else{
            rep(j, 9){
                if(j%3 == pasta[i]){
                    rep(k,9){
                        if(j/3 == k%3 && j != k) dp[i][j] += dp[i-1][j];
                    }
                }
            }
        }
    }
    rep(i,n+1){
        rep(j,9) cout << dp[i][j] << " ";
        cout << endl;
    }
}
