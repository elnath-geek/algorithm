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



double dist(pii i, pii j){
    return sqrt( pow( i.first - j.first, 2 ) + pow( i.second - j.second, 2));
}

int main(){
    int n;
    cin >> n;
    vector<pii> towns(n);
    rep(i,n){
        int x,y;
        cin >> x >> y;
        towns[i] = mp(x,y);
    }
    vint v(n);
    iota(v.begin(), v.end(), 0);
    double ans = 0;
    double p_count=0;
    do{
        p_count++;
        rep(i,n-1){
            ans += dist(towns[v[i]], towns[v[i+1]]);
        }
    } while ( next_permutation(v.begin(), v.end()) );
    ans = ans / p_count;
    fcout << ans << endl;
}
