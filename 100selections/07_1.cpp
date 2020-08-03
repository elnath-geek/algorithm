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

bool field[5010][5010];

int main(){
    int n;
    cin >> n;
    vector<pii> xy(n);
    rep(i,n) {
        cin >> xy[i].first >> xy[i].second;
        field[xy[i].first][xy[i].second] = 1;
    }
    int ans = 0;
    rep(i,n) for(int j=i+1; j<n; j++){
        int dx = xy[i].first - xy[j].first;
        int dy = xy[i].second - xy[j].second;
        int x1 = xy[i].first - dy;
        int y1 = xy[i].second + dx;
        int x2 = xy[j].first - dy;
        int y2 = xy[j].second + dx;
        if(x1<0 || y1<0 || x2<0 || y2<0) continue;
        if(x1>5000 || y1>5000 || x2>5000 || y2>5000) continue;
        if(field[x1][y1] && field[x2][y2]){
            int tmp = dx*dx + dy*dy;
            ans = max(tmp,ans);
        }
    }
    cout << ans << endl;
}
