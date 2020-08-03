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


int n, k;

int dijkstra(int a, int b, vector<vll>& edge){
    vll d(n, inf);
    d[a] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > q;
    q.push(mp(0, a));
    while(!q.empty()){
        pii node = q.top(); q.pop();
        int cost = node.first;
        int pos = node.second;
        if(cost <= d[pos]){
            rep(to,n){
                // printf("to = %d, cost = %d\n", to, edge[pos][to]);
                if(d[to] > d[pos] + edge[pos][to]){
                    d[to] = d[pos] + edge[pos][to];
                    q.push(mp(d[to], to));
                }
            }
        }
    }
    return d[b] == inf ? -1 : d[b];
}

int main(){
    cin >> n >> k;
    vector<vll> edge(n, vll(n, inf));

    rep(i,k){
        ll q, a, b, c, d, e;
        cin >> q;
        if(q == 0){
            cin >> a >> b;
            a--; b--;
            int ans = dijkstra(a, b, edge);
            cout << ans << endl;
        }else{
            cin >> c >> d >> e;
            c--; d--;
            edge[c][d] = min(edge[c][d], e);
            edge[d][c] = min(edge[d][c], e);
        }
    }

}
