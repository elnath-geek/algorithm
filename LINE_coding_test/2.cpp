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

// makefile
// c++ -std=c++11 -finput-charset=UTF-8 -o main src/*.cpp


// 2
// 001137565660 1000
// 78722
// start
// 0011375656600
// 0278722020000
// end
// start
// 0011375656602
// end
// start
// 001137565660002002
// end
// start
// 001137565660040004
// end

void print_err(int e1, int e2){
    if(e1 && e2){
        printf("staff call:1 2\n");
    }else if(e1){
        printf("staff call:1\n");
    }else if(e2){
        printf("staff call:2\n");
    }
    // exit(1);
}

bool check_sum(const char * code){
    int len = strlen(code);
    int sum=0;
    rep(i,len-1){
        sum += code[i]-'0';
    }
    // printf("sum = %d\n", sum);
    return sum%10 == code[len-1]-'0';
}

int main(){
    int n;
    cin >> n;
    map<string , int> list;
    rep(i,n){
        string code;
        int value;
        cin >> code;
        int code_len = code.length();
        if(code_len == 12){
            cin >> value;
            list[code] = value;
        }else if(code_len == 5){
            list[code] = 0;
        }
        // cout << "add map item = " << code << endl;
    }

    char buf[256];
    char code[20];
    bool start_flag = 0;
    bool point_flag = 0;
    int point;
    int pay=0;
    int err_1=0, err_2=0;
    while(fgets(buf, sizeof(buf), stdin) != NULL){
        int n = sscanf(buf, "%[a-z0-9] %d", code, &point); // 入力の読み取り、1行ずつ読む
        // printf("code = %s, point = %d\n", code, point);
        if(start_flag == 0 && strcmp(code, "start") == 0){ // まだ始まってない状態、start待ち
            if(n == 1){
                point_flag = 0;
                point = 0;
            }else if(n == 2){
                point_flag = 1;
            }
            start_flag = 1;
            pay = 0;
            err_1 = 0;
            err_2 = 0;
            // printf("reset start\n");
        }else{ // startしており、一行ずつ読んで処理する。
            if(strcmp(code, "end") == 0){ // endが来た時の処理。
                // printf("end !\n");
                start_flag = 0;
                if(err_1 || err_2){
                    print_err(err_1, err_2);
                }else{
                    if(point_flag){
                        pay -= point;
                        if(pay < 0){
                            pay = 0;
                        }
                        printf("%d\n", pay);

                    }else{
                        printf("%d\n", pay);
                    }
                }

            }else{ // 普通のコードが来た時の処理。
                // printf("normal code\n");
                if(!check_sum(code)){
                    err_2++;
                    // printf("check_sum err\n");
                }
                int code_len = strlen(code);
                // printf("code_len = %d\n", code_len);
                if(!(code_len == 13 || code_len == 16 || code_len == 18)){
                    err_2++;
                    // printf("cole_len err\n");
                }

                int value = 0;
                if(code[0] == '0' && code[1] == '2'){ // 量り売り商品の計算
                    string item_s(code, 2, 5);
                    string value_s(code, 7, 5);
                    auto it = list.find(item_s);
                    if(it == list.end()){
                        err_2++;
                        // printf("not find\n");
                    }
                    value = atoi(value_s.c_str());
                }else{ // 通常商品の計算
                    string item_s(code, 12);
                    auto it = list.find(item_s);
                    if(it == list.end()){
                        err_2++;
                        // printf("not find\n");
                    }else{
                        value = list[item_s];
                    }
                }

                // 割引がある場合の処理
                if(code_len == 15){
                    char dis_ps[3];
                    strncpy(dis_ps, code+12, 2);
                    dis_ps[2] = '\0';
                    int dis_p = atoi(dis_ps);
                    value = round( (double)value*dis_p/100 );
                }else if(code_len == 18){
                    char dis_vs[6];
                    strncpy(dis_vs, code+12, 5);
                    dis_vs[5] = '\0';
                    int dis_v = atoi(dis_vs);
                    value -= dis_v;
                    if(value <= 0){
                        err_1++;
                    }
                }

                // printf("value = %d\n", value);
                pay += value;
            }
        }

    }

}

