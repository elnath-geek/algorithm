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
    int m, n;
    pii ans;
    cin >> m;
    vector<pii> sign(m);
    rep(i,m){
        cin >> sign[i].first >> sign[i].second;
    }
    cin >> n;
    vector<pii> stars(n);
    rep(i,n){
        cin >> stars[i].first >> stars[i].second;
    }
    rep(i,n){
        int dx = stars[i].first - sign[0].first;
        int dy = stars[i].second - sign[0].second;
        // printf("dx=%d, dy=%d\n", dx, dy);
        int flag = 1;
        for(int j=1; j<m; j++){
            rep(k,n){
                if( stars[k].first == sign[j].first + dx &&
                stars[k].second ==  sign[j].second + dy){
                    flag++;
                    break;
                }
            }
            if(flag == m){
                ans.first = dx;
                ans.second = dy;
            }
        }
    }
    printf("%d %d\n", ans.first, ans.second);
}
