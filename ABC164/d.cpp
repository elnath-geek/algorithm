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
    string s;
    cin >> s;
    int n=s.size();
    int ans=0;
    set<pii> i_j;
    rep(i,n){
        for(int j=5; j<=n-i; j++){
            string slice_s = s.substr(i, j);
            int num_s = atoi(slice_s.c_str());
            if(num_s % 2019 == 0) {
                // printf("num_s=%d i=%d j=%d\n", num_s, i, j );
                i_j.insert( mp(i,i+j) );
                ans++;
                break;
            }
        }
    }

    cout << ans << endl;
}
