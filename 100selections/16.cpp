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
    vint v(n), p(n), q(n);
    rep(i,n) cin >> p[i];
    rep(i,n) cin >> q[i];
    iota(v.begin(), v.end(), 1);
    int count=0, a,b;
    do {
        count++;
        bool p_flag=1, q_flag=1;
        rep(i,n){
            if(v[i] != p[i]) p_flag = 0;
            if(v[i] != q[i]) q_flag = 0;
        }
        if(p_flag) a=count;
        if(q_flag) b=count;
    } while ( next_permutation(v.begin(), v.end()) );
    cout << abs(a-b) << endl;
}
