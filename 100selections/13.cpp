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
    int r, c;
    cin >> r >> c;
    vector<bitset<10>> a(c, bitset<10>(0) );
    rep(i,r) rep(j,c){
        bool s;
        cin >> s;
        a[j].set(i, s);
    }
    int ans=0;
    rep(bit, 1<<r){
        int count=0;
        // cout << "bit = " << bit << endl;
        rep(i,c){
            bitset<10> tmp_bit=a[i];
            // cout << "i = " << i << endl;
            rep(j,r){
                if(bit&(1<<j)) tmp_bit.flip(j);
            }
                // cout << "tmp_bit = " << tmp_bit << endl;
            int tmp=max(tmp_bit.count(), r-tmp_bit.count());
            count += tmp;
        }
        ans = max(ans, count);
    }
    cout << ans << endl;
}
