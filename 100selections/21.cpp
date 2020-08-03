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

bool isOK(int n, vll h, vll s, ll max_h){
    vll limit(n);
    rep(i,n){
        limit[i] = (max_h-h[i])/s[i];
    }
    sort(limit.begin(), limit.end());
    // rep(i,n) cout << limit[i] << " "; cout << endl;
    bool flag=1;
    rep(i,n){
        if(limit[i] < i || max_h-h[i] < 0) flag=0;
    }
    return flag;
};

int main(){
    int n;
    cin >> n;
    vll h(n), s(n);
    rep(i,n){
        cin >> h[i] >> s[i];
    }

    ll left = 0;
    ll right = inf;
    while(right != left){
        ll mid = (left + right)/2;
        if( isOK(n, h, s, mid) ) right = mid;
        else left = mid+1;
    }
    cout << right << endl;
}
