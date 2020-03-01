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

    int A,B,C,D,E,F;
    Scd2(A,B);
    Scd2(C,D);
    Scd2(E,F);

    bool wdp[100] = {};
    wdp[0] = true;
    bool sdp[10000] = {};
    sdp[0] = true;

    Rep(i,30){
        wdp[i+A] |= wdp[i];
        wdp[i+B] |= wdp[i];
    }
    Rep(i,3000){
        sdp[i+C] |= sdp[i];
        sdp[i+D] |= sdp[i];
    }

    int mans=100*A,sans=0;
    Repe(wi,31,1) Rep(si,wi*E+1){
        if( wi*100+si > F ) break;
        if( !wdp[wi]|!sdp[si] ) continue;
        if( 1.0*si/(wi*100+si) > 1.0*sans/mans ){
            mans = wi*100+si;
            sans = si;
        }
    }

    printf ("%d %d\n", mans, sans );


    return 0;
}

