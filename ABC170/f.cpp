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
#define F first
#define S second
const ll inf = 1e18;
const ll mod = 1e9 + 7;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    int h, w, k;
    pii x, y;
    cin >> h >> w >> k;
    cin >> x.F >> x.S >> y.F >> y.S;
    x.F--; x.S--; y.F--; y.S--;
    vector<vint> pond(h, vint(w, 0));
    vector<vint> ans(h, vint(w, 1e9));
    vector<vector<bool>> visit(h, vector<bool>(w, 0));
    rep(i,h){
        rep(j,w){
            char c;
            cin >> c;
            if(c == '@') pond[i][j] = 1;
        }
    }

    queue<pii> q;
    // priority_queue<tuple<int, int, int>> q;
    q.push(mp(x.F, x.S));
    ans[x.F][x.S] = 0;
    pii pos;
    while(!q.empty()){
        pos = q.front(); q.pop();
        // if(visit[pos.F][pos.S]) continue;
        // visit[pos.F][pos.S] = 1;
        rep(i,4){
            rep(j,k){
                int nx = pos.F + dx[i]*(j+1);
                int ny = pos.S + dy[i]*(j+1);
                if(nx < 0 || h <= nx || ny < 0 || w <= ny ) break;
                if(pond[nx][ny] == 0){
                    // printf("nx = %d, ny = %d\n", nx, ny);
                    if(ans[nx][ny] >= ans[pos.F][pos.S] + 1){
                        ans[nx][ny] = ans[pos.F][pos.S] + 1;
                        if(nx == y.F && ny == y.S){
                            goto exit;
                        }
                        q.push(mp(nx, ny));
                    }else break;
                }else break;
            }
        }

    }
    exit:
    // rep(i,h){
    //     rep(j,w){
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;rep(i,h);
    // }
    int ans_n = ans[y.F][y.S];
    if(ans_n == 1e9) ans_n = -1;
    cout << ans_n << endl;
}

