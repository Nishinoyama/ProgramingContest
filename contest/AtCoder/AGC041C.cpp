#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// template {{{  0 
// using {{{ 1
using ll = long long int;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vii = vector<pii>;
using vll = vector<pll>;
// }}} 1
// definition {{{ 1
// scaning {{{ 2
#define Scd(x) scanf("%d", &x)
#define Scd2(x,y) scanf("%d%d", &x, &y)
#define Scd3(x,y,z) scanf("%d%d%d", &x, &y, &z)
#define Scll(x) scanf("%lld", &x)
#define Scll2(x,y) scanf("%lld%lld", &x, &y)
#define Scll3(x,y,z) scanf("%lld%lld%lld", &x, &y, &z)
#define Scc(c) scanf("%c", &c);
#define Scs(s) scanf("%s", s);
#define Scstr(s) scanf("%s", &s);
// }}} 2
// constants {{{ 2
#define EPS (1e-7)
#define INF (2e9)
#define PI (acos(-1))
// }}} 2
// systems {{{ 2
#define Repe(x,y,z) for(ll x = z; x < y; x++)
#define Rep(x,y) Repe(x,y,0)
#define RRepe(x,y,z) for(ll x = y-z-1; x >= 0; x--)
#define RRep(x,y) RRepe(x,y,0)
// }}} 2
// output {{{ 2
#define YesNo(a) (a)?printf("Yes\n"):printf("No\n")
#define YESNO(a) (a)?printf("YES\n"):printf("NO\n")
// }}} 2
// }}} 1
// input {{{ 1
// }}} 1
// }}} 0

int main() {

    int N;
    Scd(N);

    char s3[5][5] = {
        "bbc",
        "a.c",
        "add"
    };

    char s4[6][6] = {
        "abcc",
        "abdd",
        "eegh",
        "ffgh"
    };

    char s5[7][7] = {
        "aabbc",
        "h.jjc",
        "hi..d",
        "gi..d",
        "gffee"
    };

    char s7[8][8] = {
        "n...ooz",
        "n...k.z",
        "i...kss",
        "iamm...",
        "sa.a...",
        "syya...",
        ".iinnoo"
    };

    pii dp[1012] = {};
    Rep(i,N+3) dp[i] = {0,-2};
    dp[3] = {3,-2};
    dp[6] = {3,3};
    dp[0] = {0,0};
    Rep(i,N){
        if( i == 3 ) continue;
        if( i == 6 ) continue;
        if( dp[i].second == -2 ) continue;
        if( dp[i+7].first == 0 ) dp[i+7].first = 7, dp[i+7].second = i;
        if( dp[i+4].first == 0 ) dp[i+4].first = 4, dp[i+4].second = i;
        if( dp[i+5].first == 0 ) dp[i+5].first = 5, dp[i+5].second = i;
    }

    if( N == 2 ) {
        printf ("%d\n", -1 );
        return 0;
    }

    char ans[1002][1002];

    Rep(i,N){
        Rep(j,N) ans[i][j] = '.';
    }

    int n = N;
    int m;
    int r,c;
    while(n>0){
        m = dp[n].first;
        Rep(i,m) Rep(j,m) {
            r = n-m+i, c = n-m+j;
            if( m == 3 ) ans[r][c] = s3[i][j];
            if( m == 4 ) ans[r][c] = s4[i][j];
            if( m == 5 ) ans[r][c] = s5[i][j];
            if( m == 7 ) ans[r][c] = s7[i][j];
        }
        n = dp[n].second;
    }

    Rep(i,N) printf ("%s\n", ans[i] );

    return 0;
}

