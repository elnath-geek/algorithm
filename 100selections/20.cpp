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
    int n;
    cin >> n;
    vint a(n), b(n), c(n);
    ll ans=0;
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    rep(i,n) cin >> c[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    // rep(i,n) cout << a[i] << " "; cout << endl;
    // rep(i,n) cout << b[i] << " "; cout << endl;
    // rep(i,n) cout << c[i] << " "; cout << endl;

    rep(i,n){
        ll a_idx = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        ll c_idx = upper_bound(c.begin(), c.end(), b[i]) - c.begin();
        ans += a_idx * (n-c_idx);
        // printf("a_i = %d, c_i = %d\n", a_idx, c_idx);
    }

    cout << ans << endl;
}
