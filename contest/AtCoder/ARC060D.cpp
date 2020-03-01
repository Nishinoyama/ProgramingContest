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

ll f( ll b, ll n ){
    ll sum = 0;
    while( n ){
        sum += n%b;
        n = n/b;
    }
    return sum;
}

int main() {

    ll n,s,b = 1e13;
    Scll2(n,s);

    if( n < s ){
        b = -1;
    }else if( n == s ){
        b = n+1;
    }else{
        ll nn = sqrt(n)+1;
        Repe(i,nn,2){
            // printf ("%lld = %lld\n", i, f(i,n) );
            if( f(i,n) == s ){
                b = min(b,i);
            }
        }
        Repe(i,nn,1){
            ll r = n/i; ll l = n/(i+1); ll c;
            // (l,r]
            // printf ("i=%lld (%lld,%lld]\n", i, l, r );
            while( r-l>1 ){
                c = (r+l)/2;
                if( f(c,n) <= s ) r = c;
                else l = c;
            }
            if( f(r,n) == s ) b = min(b,r);
        }
        if( b == 1e13 ) b = -1;
    }

    printf ("%lld\n", b );

    // Repe(i,n+3,2){
    //     if( f(i,n) == s ) {
    //         printf ("ans = %lld\n", i);
    //         break;
    //     }
    // }

    return 0;
}

