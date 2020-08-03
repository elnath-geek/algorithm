#include <bits/stdc++.h>
#include <time.h>
// #include <iostream.h>
#include <stdio.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::bitset;

#define rep(i,n)    for(int i=0; i<(int)n; i++)
#define reps(i,s,e) for(int i=s; i<(int)e; i++)
#define coutd(i) cout << std::fixed << std::setprecision(i)
typedef long double ld;
typedef long long ll;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;

template<class T>
using Set = std::set<T>;
template<class T, class U>
using Map = std::map<T, U>;

template<class T>
using Graph = vector<vector<T>>;

const int INT_BIG = 1<<28;

int main() {
    clock_t start = clock();
    int D;
    cin >> D;
    vint downrate(26);
    Graph<int> uppoint(D, vint(26));
    rep(i, 26) {
        cin >> downrate[i];
    }

    rep(i, D) {
        rep(j, 26) {
            cin >> uppoint[i][j];
        }
    }

    // ll satisfy = 0;
    // vint schedule(D);
    // rep(i, D) {
    //     cin >> schedule[i];
    //     schedule[i]--;
    //     satisfy += uppoint[i][schedule[i]];
    //     lastDay[schedule[i]] = i;
        // rep(j, 26) {
        //     satisfy -= (i - lastDay[j]) * downrate[j];
        // }
    //     cout << satisfy << endl;
    // }

    vint lastDay(26, -1);

    ll satisfy = 0;
    vint schedule(D);
    rep(i, D) {
        ll satisfylossmax = 0;
        ll satisfyid = -1;
        rep(j, 26) {
            ll satisfyloss = (i - lastDay[j]) * downrate[j] + uppoint[i][j];
            if (satisfylossmax < satisfyloss) {
                satisfylossmax = satisfyloss;
                satisfyid = j;
            }
        }

        satisfy += uppoint[i][satisfyid];
        lastDay[satisfyid] = i;
        rep(j, 26) {
            satisfy -= (i - lastDay[j]) * downrate[j];
        }
        schedule[i] = satisfyid;
    }

    vector<Set<int>> dayset(26);
    rep(i, 26){
        dayset[i].insert(-1);
        dayset[i].insert(D);
    }
    rep(i, D) {
        dayset[schedule[i]].insert(i);
        satisfy += uppoint[i][schedule[i]];
        lastDay[schedule[i]] = i;
        rep(j, 26) {
            satisfy -= (i - lastDay[j]) * downrate[j];
        }
        // cout << satisfy << endl;
    }

    while(true) {
        clock_t end = clock();
        const double time = static_cast<double>(end-start) / CLOCKS_PER_SEC;
        if (time > 1.5) {
            break;
        }

        // int d, q;
        // cin >> d >> q;
        // d--;
        // q--;
        int d = rand() % D;
        int q = rand() % 25;
        ll tmpsatisfy = satisfy;
        tmpsatisfy += -uppoint[d][schedule[d]] + uppoint[d][q];

        // 追加したことによる減少分
        auto it = dayset[q].lower_bound(d);
        int nextp = *it;
        it--;
        int befp = *it;
        int p = nextp - d;
        int k = (d-befp);
        // cout << befp << " shita " << nextp << endl;
        // cout << k << " " << p << endl;
        // cout << (p*(p+1)/2+k*p-p) << endl;
        // tmpsatisfy -= (2*(((p)*(p+1)/2) + k*p - 1*p )*k-p*k*k+p*k)/2*downrate[q];
        tmpsatisfy += k*p*downrate[q];


        // 減らしたことによる増加分
        auto it2 = dayset[schedule[d]].upper_bound(d);
        auto it3 = dayset[schedule[d]].find(d);
        nextp = *it2;
        it3--;
        befp = *it3;
        // cout << befp << " ue " << nextp << endl;
        p = nextp - d;
        k = (d-befp);
        // cout << k << " " << p << endl;
        tmpsatisfy -= k*p*downrate[schedule[d]];

        if (tmpsatisfy > satisfy) {
            satisfy = tmpsatisfy;
            dayset[schedule[d]].erase(d);
            dayset[q].insert(d);
            schedule[d] = q;
        }
    }

    for (auto &id: schedule) {
        cout << id+1 << endl;
    }
}
