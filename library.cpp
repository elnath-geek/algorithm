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

// mod を取りながら累乗の計算をする。
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

// コンビネーションのmod、
// 最初にCOMinit()した後に、COM(n,k) で n_C_k が取れる。
const int MAX_N= 200000;
ll fac[MAX_N], finv[MAX_N], inv[MAX_N];
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX_N; i++){
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = mod - inv[mod%i] * (mod / i) % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}

ll COM(int n, int k){
    if(n<k) return 0;
    if(n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n-k] % mod) % mod;
}

// フォーマットが厳格に決まった時の入力の取り方。
int input_sample(){
    char item[10];
    int value;
    int h, m, s, f;
    double d;

    // これが一番安全かと思われる。
    // fgetsでbuf文字分受け取ってから、sscanfでフォーマット指定して変数に入れる。
    // sscanfの戻り値 n は受け取った変数の数になるから、それでエラー処理ができる。
    char buf[256];
    while(fgets(buf, sizeof(buf), stdin) != NULL){
        int n = sscanf(buf, "%[a-z] %d", item, &value);
        int n = sscanf(buf, "%2d %*[:]%2d %*[:]%2d %*[.]%d %lf", &h, &m, &s, &f, &d); // hh:mm:ss.fff xx.f<LF>
        if(n != 2){
            printf("error");
            return 1;
        }
        cout << "n = " << n << endl;
        cout << "item = " << item << endl;
        cout << "value = " << value << endl;
    }

    // 1行のstringを読み取るだけ、stringの分割はめんどくさいなーのお気持ち。
    string line;
    while(!cin.eof()){
        getline(cin, line);
        cout << "line = " << line << endl;
    }

    // ストリームに流れてきた物でフォーマットにあうものを読み続けるので、
    // 入力が途切れてもお構いなしで次を待つクソ仕様なので使わない。
    scanf("%3[a-z] %*s%d", item, &value);
}


// union_findの実装サンプル
int root[MAX_N], t_rank[MAX_N]; // tree_rank (rankが予約語だから)
void UFinit(int n){
    rep(i,n){
        root[i] = i;
        t_rank[i] = 0;
    }
}
int find(int x){
    if(root[x] == x) return x;
    else return root[x] = find(root[x]);
}
void unite(int x, int y){
    x = find(x); y = find(y);
    if(x == y) return;
    if(t_rank[x] < t_rank[y]){
        root[x] = y;
    }else{
        root[y] = x;
        if(t_rank[x] == t_rank[y]){
            t_rank[x]++;
        }
    }
}
bool same(int x, int y){
    return find(x) == find(y);
}


int main(){

}

