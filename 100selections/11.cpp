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
    vector<int> k(m);
    vector<vint> s(m);
    rep(i,m){
        cin >> k[i];
        s[i].resize(k[i]);
        rep(j,k[i]){
            cin >> s[i][j];
        }
    }
    vint p(m);
    rep(i,m) cin >> p[i];

    int ans = 0;
    for(int bit=0; bit<(1<<n); bit++){
        bool flag = 1;
        rep(i, m){
            int tmp=0;
            rep(j, k[i]){
                if( (bit >> (s[i][j]-1) )& 1 ) tmp++;
            }
            if(tmp%2 != p[i]){
                flag = 0;
            }
        }
        if(flag){
            ans++;
            // printf("%d\n", bit);
        }
    }
    cout << ans << endl;
}
