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
    ll c_d, s_n, o_n;
    cin >> c_d >> s_n >> o_n;
    vll s_pos(s_n, 0);
    vll order(o_n);
    for(int i=1; i<s_n; i++) cin >> s_pos[i];
    rep(i, o_n) cin >> order[i];
    sort(s_pos.begin(), s_pos.end());
    // rep(i,s_n) cout << s_pos[i] << " "; cout << endl;
    sort(order.begin(), order.end());

    ll ans=0;

    rep(i,o_n){
        ll idx = distance(s_pos.begin(), lower_bound(s_pos.begin(), s_pos.end(), order[i]) );
        ll dist=0;
        if(idx == 0){
            dist = min(s_pos[idx]-order[i], c_d-s_pos[s_n-1]+order[i] );
        }else if(idx == s_n){
            dist = min(order[i]-s_pos[s_n-1], c_d-order[i]+s_pos[0]);
        }else{
            dist = min(s_pos[idx]-order[i], order[i]-s_pos[idx-1]);
        }
        ans += dist;
        // printf("order[i] = %lld, idx = %lld, dist = %lld\n", order[i], idx, dist);
    }
    cout << ans << endl;
}
