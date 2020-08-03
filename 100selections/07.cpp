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

typedef struct Edge {
    double len_pow2;
    double center_x;
    double center_y;
    double vec_x;
    double vec_y;

} Edge;

bool isCrossEdge(Edge* a, Edge* b){
    return  a->len_pow2 == b->len_pow2 &&
            a->center_x == b->center_x &&
            a->center_y == b->center_y &&
            a->vec_x * b->vec_x + a->vec_y * b->vec_y == 0;
}

int main(){
    int n;
    cin >> n;
    int x[3010];
    int y[3010];
    rep(i,n) cin >> x[i] >> y[i];
    int edge_num = n*(n-1)/2;
    vector<Edge> edges(edge_num);
    int ans=0;
    int index=0;
    rep(i,n){
        for(int j=i+1; j<n; j++){
            edges[index].len_pow2 = pow(x[i]-x[j], 2) + pow(y[i]-y[j], 2);
            edges[index].center_x = (double)(x[i]+x[j])/2;
            edges[index].center_y = (double)(y[i]+y[j])/2;
            edges[index].vec_x = x[i]-x[j];
            edges[index].vec_y = y[i]-y[j];
            index++;
        }
    }
    rep(i, edge_num) for(int j=i+1; j<edge_num; j++){
        if(isCrossEdge(&edges[i], &edges[j])){
            int tmp = edges[i].len_pow2 / 2;
            if(tmp > ans) ans = tmp;
        }
    }
    cout << ans << endl;
}
