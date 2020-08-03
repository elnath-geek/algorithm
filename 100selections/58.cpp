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
#define rep(i,n)    for(int i=0; i<(ll)n; i++)
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
    int n, m, k, s;
    int p, q;
    cin >> n >> m >> k >> s;
    cin >> p >> q;
    vector<vint> edge;
    edge.resize(n);
    queue<pll> que;
    vint cost(n,p);

    rep(i,k){
        int c;
        cin >> c;
        c--;
        que.push( mp(c, s) );
        cost[c] = 1e9;
    }
    rep(i,m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        edge[a].pb(b);
        edge[b].pb(a);
    }

    while(!que.empty()){
        pii z_town = que.front(); que.pop();
        for(int i_town : edge[z_town.F]){
            if(cost[i_town] >= q) continue;
            cost[i_town] = q;
            if(z_town.S > 1) que.push(mp(i_town, z_town.S-1));
        }
    }
    cost[0] = 0;
    cost[n-1] = 0;
    // rep(i,n) printf("cost[%d] = %lld\n", i, cost[i]);

    vll d(n, inf);
    d[0] = 0;
    priority_queue<pll, vector<pll>, greater<pll> > pq;
    pq.push(mp(0, 0));
    while(!pq.empty()){
        pll now = pq.top(); pq.pop();
        int town = now.S;
        // printf("cost = %lld, town = %lld\n", tmp_cost, town);
        for(int next_town: edge[town]){
            if(d[next_town] > d[town] + cost[next_town]){
                d[next_town] = d[town] + cost[next_town];
                pq.push( mp(d[next_town], next_town) );
            }
        }
    }
    cout << d[n-1] << endl;
}
