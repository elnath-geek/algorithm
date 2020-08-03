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
#define rep(i,n)    for(int i=0; i<(ll)n; i++)
#define mp(a,b) make_pair(a,b)
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second
const ll inf = 1e18;
const ll mod = 1e9 + 7;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

// mod. m での a の逆元 a^(-1) を計算する。
ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main(){
    ll n;
    cin >> n;
    ll match=0;
    ll start=0;
    ll end=0;
    ll max_l=0;
    ll start_max_r=0;
    ll add_max=0;
    rep(i,n){
        ll left=0, right=0;
        string s;
        cin >> s;
        ll count=0;
        rep(j, s.size()){
            if(s[j] == ')') count--;
            if(s[j] == '(') count++;
            left = min(left, count);
        }
        count = 0;
        for(int j=s.size()-1; j>=0; j--){
            if(s[j] == ')') count--;
            if(s[j] == '(') count++;
            right = max(right, count);
        }
        // printf("F = %d, S = %d\n", left, right);
        match += left;
        match += right;
        if(left == 0 && right > 0){
            start = 1;
            start_max_r = max(start_max_r, right);
        }
        if(left < 0 && right == 0) end = 1;
        max_l = min(max_l, left);
        if(count > 0) add_max += count;
    }
    string ans = "No";
    if(start && end && match==0 && add_max >= max_l*-1) ans = "Yes";
    cout << ans << endl;
}

