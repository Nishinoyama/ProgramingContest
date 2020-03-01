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

ll gcd( ll a, ll b ){
    if( a < b ) swap(a,b);
    ll t = a;

    while( a%b ){
        t = a;
        a = b;
        b = t%b;
    }

    return b;
}

ll lcm( ll a, ll b ){
    return a/gcd(a,b)*b;
}

int main() {

    int N;
    ll M;
    Scd(N);
    Scll(M);
    vector<ll> a(N);
    Rep(i,N) Scll(a[i]);

    int ans = 0;
    ll e = 1;

    Rep(i,N){
        e = lcm(a[i],e);
        if( e/2 > M ) {
            ans = -1;
            break;
        }
    }

    Rep(i,N){
        if( (e/a[i])%2 != 1 ) ans = -1;
    }

    if( ans == -1 ){
        printf ("%d\n", 0);
        return 0;
    }

    printf ("%lld\n", (M+e/2)/e);


    return 0;
}

