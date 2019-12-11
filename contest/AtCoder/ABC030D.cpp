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

    int N,a;
    Scd2(N,a);
    a--;

    char s[123456];
    Scs(s);
    int M = strlen(s);

    vi b(N);
    Rep(i,N){
        Scd(b[i]);
        b[i]--;
    }

    int from = a;
    int cnt = 0;
    vi dist(N,-1);
    while( dist[from] == -1 ){
        dist[from] = cnt++;
        from = b[from];
    }

    int loop = from;
    int loopN = cnt-dist[from];


    int k = 0;
    Rep(i,M){
        k *= 10;
        k += s[i]-'0';
        if( k > N*10 ){
            break;
        }
    }
    from = a;
    cnt = 0;
    while(k){
        // printf ("k=%d, f=%d\n", k, from );
        cnt++;
        k--;
        from = b[from];
        if( from == loop ){
            ll m = 0;
            Rep(i,M){
                m *= 10;
                m += s[i]-'0';
                m %= loopN;
            }
            m += 1ll*loopN*cnt-cnt;
            m %= loopN;
            k=m;
        }
    }

    printf ("%d\n", from+1 );

    return 0;
}

