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
    int n,k;
    cin >> n >> k;
    vector<pii> cost(n);
    vector<vint> edge;
    vector<vll> table(n, vll(n, inf));
    edge.resize(n);
    rep(i,n){
        int c, r;
        cin >> c >> r;
        cost[i] = mp(c, r);
    }
    rep(i,k){
        int a, b;
        cin >> a >> b;
        a--; b--;
        edge[a].pb(b);
        edge[b].pb(a);
    }
    queue<pii> q;
    rep(i,n){
        vint visit(n, 0);
        visit[i] = 1;
        q.push( mp(i, cost[i].S));
        pii now;
        while(!q.empty()){
            now = q.front(); q.pop();
            for(int next_town : edge[now.F]){
                if(visit[next_town] == 1) continue;
                visit[next_town] = 1;
                table[i][next_town] = cost[i].F;
                if(now.S > 1) q.push(mp(next_town, now.S-1));
            }
        }
        table[i][i] = 0;
    }

    // rep(i,n){
    //     cout << i << " ";
    //     rep(j,n) cout << table[i][j] << " ";
    //     cout << endl;
    // }

    vll d(n, inf);
    d[0] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(mp(0,0));
    pii now;
    while(!pq.empty()){
        now = pq.top(); pq.pop();
        rep(next_town,n){
            if(d[next_town] > d[now.S] + table[now.S][next_town]){
                d[next_town] = d[now.S] + table[now.S][next_town];
                pq.push(mp(d[next_town], next_town));
            }
        }
    }
    cout << d[n-1] << endl;

}
