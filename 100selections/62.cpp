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



int main(){
    int h,w;
    cin >> h >> w;
    int cc[10][10];
    int a[10]= {0};
    rep(i,10){
        rep(j,10) cin >> cc[i][j];
    }
    rep(i,h) rep(j,w){
        int num;
        cin >> num;
        if(num != -1){
            a[num]++;
        }
    }

    rep(k,10){
        rep(i,10){
            rep(j,10){
                cc[i][j] = min(cc[i][j], cc[i][k] + cc[k][j]);
            }
        }
    }
    ll ans=0;
    rep(i,10){
        ans += a[i]*cc[i][1];
    }
    cout << ans << endl;
}
