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

ll modpow(ll a, ll n){
    ll res = 1;
    while(n>0){
        if(n&1){
            res = res * a % mod;
        }
        a = a * a % mod;
        n >>=1;
    }
    return res;
}

int main(){
	int D; cin >> D;
	int C[30] = {};
	for(int i = 1; i <= 26; i++) cin >> C[i];
	int S[370][30] = {};
	for(int i = 1; i <= D; i++){
		for(int j = 1; j <= 26; j++){
			cin >> S[i][j];
		}
	}
	int ans[370] = {};
	int L[30] = {};
	for(int i = 1; i < D; i+= 2){
		int E[700] = {};
		for(int j = 1; j <= 676; j++){
			int p = (j - 1) % 26 + 1; // i日目
			int q = (j - 1) / 26 + 1; // i+1日目
			int M[30] = {};
			for(int k = 1; k <= 26; k++){
				M[k] = L[k];
			}
			E[j] += S[i][p] + C[p] * (i - M[p]) * min(D-i, 5);
			M[p] = i;
			E[j] += S[i+1][q] + C[q] * (i + 1 - M[q]) * min(D-i, 5);
		}
		int a = 0; int mx = -1145141919;
		for(int j = 1; j <= 676; j++){
			if(E[j] > mx){
				a = j; mx = E[j];
			}
		}
		ans[i] = (a-1) % 26 + 1; ans[i+1] = (a-1) / 26 + 1;
		L[(a-1) % 26 + 1] = i; L[(a-1) / 26 + 1] = i + 1;
	}
	for(int i = D; i <= D; i++){
		int E[30] = {};
		for(int j = 1; j <= 26; j++){
			E[j] = S[i][j] + C[j] * (i - L[j]);
		}
		int a = 0; int mx = -1145141919;
		for(int j = 1; j <= 26; j++){
			if(E[j] > mx){
				a = j; mx = E[j];
			}
		}
		ans[i] = a; L[a] = i;
	}
	for(int i = 1; i <= D; i++) cout << ans[i] << endl;
}
