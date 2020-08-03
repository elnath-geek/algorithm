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

ld calTime(ld x, ld p){
    return x + p/pow(2, x/1.5);
}

int main(){
    ld p;
    cin >> p;
    ld left = 0.0;
    ld right = inf;
    rep(i,500){
        ld m1 = (left*2+right)/3;
        ld m2 = (left+right*2)/3;
        if(calTime(m1, p) < calTime(m2, p)) right = m2;
        else left = m1;
    }
    fcout << calTime(right, p) << endl;
}
