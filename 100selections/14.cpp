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

int main(){
    int n, k;
    cin >> n >> k;
    vll a(n);
    rep(i,n) cin >> a[i];
    ll ans=inf;
    rep(bit, (1<<n)){
        if( (int)bitset<15>(bit).count() != k) continue;
        ll now_h=0;
        ll count=0;
        // cout << bitset<15>(bit) << endl;
        rep(pos,n){
            if( (bitset<15>(bit) & bitset<15>(1<<pos))== bitset<15>(1<<pos)){
                if(now_h >= a[pos]) count += now_h-a[pos]+1;
                now_h++;
            }
            now_h = max(now_h, a[pos]);
            // cout << now_h << endl;
        }
        ans = min(ans, count);
    }
    cout << ans << endl;
}
