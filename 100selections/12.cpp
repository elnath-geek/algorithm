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
    int n, m;
    cin >> n >> m;
    vector< bitset<12> > p2p(n, bitset<12>(0));
    rep(i,n) p2p[i].set(i);
    rep(i,m){
        int x, y;
        cin >> x >> y;
        p2p[x-1].set(y-1);
        p2p[y-1].set(x-1);
    }

    int ans=1;
    for(int bit=0; bit<(1<<n); bit++){
        rep(i,n){
            if(bit & 1<<i){
                if( (bitset<12>(bit) & p2p[i]) != bitset<12>(bit) ){
                    break;
                }
            }
            if(i+1 == n) ans = max(ans, (int)bitset<12>(bit).count() );
        }
    }
    cout << ans << endl;
}
