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

int ice[100][100] = {0};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int m,n;
int ans = 0;

void dfs_count(int x, int y, int count){
    ice[x][y] = 0;
    count++;
    ans = max(ans, count);
    rep(i, 4){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if( nx < 0 || n <= nx || ny < 0 || m <= ny) continue;
        if(ice[nx][ny] == 1){
            dfs_count(nx, ny, count);
        }
    }
    ice[x][y] = 1;
}

int main(){
    cin >> m >> n;
    rep(i,n) rep(j,m) cin >> ice[i][j];
    rep(i,n) rep(j,m) {
        if(ice[i][j] == 1){
            dfs_count(i, j, 0);
        }
    }
    cout << ans << endl;
}
