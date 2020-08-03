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

int grid[55][55] = {0};
int dist[55][55] = {0};

int main(){
    int h, w, count=0;
    cin >> h >> w;
    rep(y,h) rep(x, w){
        char s;
        cin >> s;
        if(s == '#'){
            grid[x][y] = 1;
            count++;
        }
    }
    dist[0][0] = 1;
    queue<pii> q;
    q.push(mp(0,0));
    while(!q.empty()){
        pii pos = q.front(); q.pop();
        // printf("pos %d,%d\n", pos.first, pos.second);
        rep(i,4){
            int nx = pos.first + dx[i];
            int ny = pos.second + dy[i];
            if( nx < 0 || w <= nx || ny < 0 || h <= ny ) continue;
            if(grid[nx][ny] == 0 && dist[nx][ny] == 0){
                dist[nx][ny] = dist[pos.first][pos.second] + 1;
                q.push(mp(nx, ny));
            }
            if(nx == h-1 && ny == w-1) break;
        }
    }
    int ans = h*w - count - dist[w-1][h-1];
    if(dist[w-1][h-1] == 0) ans = -1;
    cout << ans << endl;
}
