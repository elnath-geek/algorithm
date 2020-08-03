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
    string s;
    cin >> n >> s;
    int ans=0;
    rep(i, 10) rep(j, 10) rep(k, 10){
        int flag=0;
        for(int l=0; l<n; l++){
            int num = s[l]-'0';
            if( num == k && flag==2) flag=3;
            if( num == j && flag==1) flag=2;
            if( num == i && flag==0) flag=1;
            // printf("%d%d%d num=%d flag=%d\n", i,j,k, num, flag);
        }
        if(flag==3){
            ans++;
            // printf("%d%d%d flag=%d\n", i,j,k, flag);
        }
    }
    cout << ans << endl;
}
