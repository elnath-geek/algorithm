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
const ll inf = 1e18;
const ll mod = 1e9 + 7;

int g[110][110] = {0}, d[110]= {0}, f[110]= {0};
bool visited[110] = {0};

int dfs(int time, int pos){
    visited[pos] = 1;
    d[pos] = time;
    time += 1;
    rep(i,110){
        if(g[pos][i] == 1 && visited[i] == 0){
            time = dfs(time, i);
        }
    }
    f[pos] = time;
    time += 1;
    return time;
}

int main(){
    int n;
    cin >> n;
    int time=1;
    rep(i,n){
        int index, k;
        cin >> index >> k;
        rep(j,k){
            int to;
            cin >> to;
            g[i][to-1] = 1;
        }
    }
    dfs(time, 0);
    rep(i,n) printf("%d %d %d\n", i+1, d[i], f[i]);
}
