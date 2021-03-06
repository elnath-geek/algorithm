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

ll gcd(ll a, ll b){
    if(a%b == 0){
        return b;
    }else{
        return gcd(b, a%b);
    }
}

// mod.m での a の逆元 a^(-1) を計算する。
ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while(b){
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

bool minPrime[1000010];

void eratosthenes(){
    rep(i,1000010) minPrime[i] = 1;
    minPrime[0] = minPrime[1] = 0;
    rep(i,1000010){
        if(minPrime[i] == 1){
            for(int j=i; j<1000010; j+=i){
                minPrime[j] = i;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    vint a(n);
    rep(i, n) cin >> a[i];

    eratosthenes();
    bool pairwiseFlag=1;
    set<int> primes;
    rep(i,n){
        int tmp = a[i];
        while(tmp > 1){
            if(primes.count(minPrime[tmp]) == 1){
                pairwiseFlag = 0;
                break;
            }
            primes.insert(minPrime[tmp]);
            tmp = minPrime[tmp];
        }
    }

    int allgcd = a[0];
    rep(i,n) allgcd = gcd(allgcd, a[i]);

    if(pairwiseFlag){
        cout << "pairwise coprime" << endl;
    } else if(allgcd == 1){
        cout << "setwise coprime" << endl;
    } else {
        cout << "not coprime" << endl;
    }
}

