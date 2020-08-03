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

vector<vint> tree;
vint ans;
vint query;

void dfs(int pos, int c, vint& visited){
    visited[pos] = 1;
    c += query[pos];
    ans[pos] += c;
    // printf("pos = %d, c = %d\n", pos, c);
    rep(i, tree[pos].size()){
        if(visited[ tree[pos][i] ] == 0) dfs(tree[pos][i], c, visited);
    }
}

int main(){
    int n, q;
    cin >> n >> q;
    tree.resize(n);
    ans.resize(n);
    query.resize(n);
    vint visited(n,0);
    rep(i,n-1){
        int from, to;
        cin >> from >> to;
        tree[from-1].pb(to-1);
        tree[to-1].pb(from-1);
    }
    rep(i,q){
        int p, x;
        cin >> p >> x;
        query[p-1] += x;
    }
    dfs(0, 0, visited);
    rep(i,n) cout << ans[i] << " "; cout << endl;
}
