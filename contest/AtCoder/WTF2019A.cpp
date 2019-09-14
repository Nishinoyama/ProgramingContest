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

    int N,K;
    Scd2(N,K);
    vi a(N);
    Rep(i,N) Scd(a[i]);

    vi ans;
    int open = -1;
    int prev = -1;
    int fale = 0;
    K++;
    while(K){
        int mi = INF;
        Rep(i,N){
            if( a[i] < mi && prev != i ){
                open = i;
                mi = a[i];
            }
        }
        Rep(i,N) if( i != open && i != prev ) {
            if( a[i] == 0 ) fale = 1;
            ans.push_back(i+1), a[i]--;
        }
        if( a[open] == 0 ) fale = 1;
        ans.push_back(open+1), a[open]--;
        prev = open;
        K--;
    }

    printf ("%d\n", N = fale ? -1 : (int)ans.size() );
    // N = ans.size();
    Rep(i,N) printf ("%d%c", ans[i], i == N-1 ? '\n' : ' ' );

    return 0;
}



