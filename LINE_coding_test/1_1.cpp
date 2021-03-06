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

int xyz[500010][3];  // X, Y, Zを記憶する

int main(){
    // 入力の受け取り
    int n;
    cin >> n;
    vector<vint> a(n,vint(n));
    vector<vint> b(n,vint(n));
    map<int, pii> a_map;
    map<int, pii> b_map;

    rep(i,n) rep(j,n){
        int tmp;
        cin >> tmp;
        a[i][j] = tmp;
        a_map[tmp] = mp(i,j);
    }
    rep(i,n) rep(j,n){
        int tmp;
        cin >> tmp;
        b[i][j] = tmp;
        b_map[tmp] = mp(i,j);
    }

    // 達成可能かどうかの判断をする。
    // 1回のシフトで変化するマスの数はn個であり、これはn-1個の互換であると考えられる。
    // 初期状態と完成状態とで違うますの数が互換の定数倍でない場合は達成が不可能である。
    int diff_num = 0;
    vint visit(n, 0);
    rep(i,n) rep(j,n){
        if(a[i][j] == b[i][j] || visit[a[i][j]] == 1) continue;
        else{
            int loop=0;
            int num = a[i][j];
            while(1){
                loop++;
                visit[num] = 1;
                pii pos = b_map[num];
                // printf("pos = %d, %d, loop = %d\n", pos.F, pos.S, loop);
                if(pos.F == i, pos.S == j){
                    diff_num += loop-1;
                    break;
                }else{
                    num = a[pos.F][pos.S];
                }
            }
        }
    }
    // cout << "diff_num" << diff_num << endl;;
    if(diff_num%(n-1) != 0){
        cout << "no" << endl;
        return 0;
    }else{
        cout << "yes" << endl;
        // これ以降は達成可能な場合の手順について考える。
        int L=0;
        rep(i,n) rep(j,n){
            if(a[i][j] == b[i][j]) continue;
            else{
                // 盤面の左上から数字を埋めていく。
                // a_mapで欲しい数字の場所を探して、見つけた数字を動かしていく。

                pii pos = a_map[b[i][j]]; // b[i][j]の数を探す。
                int x_move = 0;
                int y_move=0;
                while(abs(j - pos.S) > x_move ){ // j列まで動かす。
                    xyz[L][0] = 1;
                    xyz[L][1] = pos.F+1;
                    if(j - pos.S > 0){
                        xyz[L][2] = 1;
                    }else{
                        xyz[L][2] = 2;
                    }
                    L++;
                    x_move++;
                }
                while(y_move > 0){ // i行まで下げる。
                    xyz[L][0] = 2;
                    xyz[L][1] = j+1;
                    xyz[L][2] = 1;
                    L++;
                    y_move--;
                }



            }
        }
        cout << L << endl;
        rep(i,L){
            printf("%d %d %d\n", xyz[i][0], xyz[i][1], xyz[i][2]);
        }
    }
}

