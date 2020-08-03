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
    int n;
    cin >> n;
    ll ans=0;
    vector<ll> a(n), b(n);
    rep(i,n){
        cin >> a[i] >> b[i];
        ans += b[i]-a[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll start = a[n/2];
    ll end = b[n/2];
    rep(i,n){
        ans += abs(a[i] - start);
        ans += abs(b[i] - end);
    }
    // printf("start = %lld, end = %lld\n", start, end);
    cout << ans << endl;
}
