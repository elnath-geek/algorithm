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

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    int r,c;
    pii s, g;
    cin >> r >> c;
    cin >> s.second >> s.first >> g.second >> g.first;
    s.first--; s.second--; g.first--; g.second--;
    vector<vint> maze(c, vint(r,0));
    vector<vint> ans(c, vint(r,-1));
    rep(y,r) rep(x,c){
        char s;
        cin >> s;
        if(s == '#') maze[x][y] = 1;
    }
    queue<pii> que;
    que.push(s);
    ans[s.first][s.second] = 0;
    while(!que.empty()){
        pii pos = que.front(); que.pop();
        // printf("pos %d, %d\n", pos.first, pos.second);
        rep(i,4){
            int nx = pos.first + dx[i];
            int ny = pos.second + dy[i];
            if(maze[nx][ny] == 0 && ans[nx][ny] == -1){
                ans[nx][ny] = ans[pos.first][pos.second] + 1;
                que.push(mp(nx, ny));
            }
        }
    }
    cout << ans[g.first][g.second] << endl;
}
