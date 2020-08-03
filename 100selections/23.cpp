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


int main(){
    ll n, m;
    cin >> n >> m;
    vll p(n+1, 0);
    for(int i=1; i<n+1; i++) cin >> p[i];
    vll p_by2( (n+1)*(n+2)/2 );
    ll count=0;
    rep(i,n+1) for(int j=i; j<n+1; j++){
        p_by2[count] = p[i] + p[j];
        count++;
    }
    sort(p_by2.begin(), p_by2.end());
    ll ans=0;
    rep(i, p_by2.size()){
        // cout << p_by2[i] << " ";
        ll diff = m - p_by2[i];
        if(diff < 0) continue;
        ll ans_idx = upper_bound(p_by2.begin(), p_by2.end(), diff) - p_by2.begin();
        ans = max(ans, p_by2[i] + p_by2[ans_idx-1]);
    }
    // cout << endl;
    cout << ans << endl;
}

