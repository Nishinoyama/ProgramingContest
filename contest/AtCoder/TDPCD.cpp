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

    static double dp[204][104][104] = {};
    static double dpy[204][104][104] = {};
    // dp[2n][3n][5n];
    dp[0][0][0] = 1.0;

    int N; ll D;
    Scd(N); Scll(D);

    int di = 2;

    vi d(10,0);

    while( D != 1 && di < 6 ){
        if( D % di == 0 ){
            D /= di;
            d[di]++;
        }else{
            di++;
        }
    }

    if( D > 1 ) dp[0][0][0] = 0;

    Rep(i,N){
        Rep(i2,i*2+2){
            Rep(i3,i+2){
                Rep(i5,i+2){
                    dpy[i2][i3][i5]     += dp[i2][i3][i5] / 6;
                    dpy[i2+1][i3][i5]   += dp[i2][i3][i5] / 6;
                    dpy[i2][i3+1][i5]   += dp[i2][i3][i5] / 6;
                    dpy[i2+1+1][i3][i5] += dp[i2][i3][i5] / 6;
                    dpy[i2][i3][i5+1]   += dp[i2][i3][i5] / 6;
                    dpy[i2+1][i3+1][i5] += dp[i2][i3][i5] / 6;
                }
            }
        }
        Rep(i2,i*2+4){
            Rep(i3,i+4){
                Rep(i5,i+4){
                    dp[i2][i3][i5] = dpy[i2][i3][i5];
                    dpy[i2][i3][i5] = 0;
                }
            }
        }
    }

    double ans = 0;
    Repe(i2,N*2+1,d[2]){
        Repe(i3,N+1,d[3]){
            Repe(i5,N+1,d[5]){
                // printf( "[%lld][%lld][%lld]=%lf\n",i2,i3,i5,dp[i2][i3][i5]);
                ans += dp[i2][i3][i5];
            }
        }
    }
    printf ("%.19lf\n", ans );

    return 0;
}



