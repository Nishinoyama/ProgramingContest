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

    int L1,R1,L2,R2,L3,R3;
    Scd2(L1,R1);
    Scd2(L2,R2);
    Scd2(L3,R3);

    int S1 = R1-L1+1;
    int S2 = R2-L2+1;
    int S3 = R3-L3+1;

    double ans = 0;
    double tmp1;
    double tmp2;
    Repe(i,R1+1,L1){
        if( i < L2 ) tmp1 = 1.0;
        else if( i >= R2 ) tmp1 = 0;
        else tmp1 = 1.0*(R2-i)/S2;
        if( i < L3 ) tmp2 = 1.0;
        else if( i >= R3 ) tmp2 = 0;
        else tmp2 = 1.0*(R3-i)/S3;
        ans += (tmp1*tmp2)/S1;
    }

    printf ("%.12lf\n", ans );

    return 0;
}

