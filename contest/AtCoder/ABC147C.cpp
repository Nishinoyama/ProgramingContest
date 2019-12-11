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
    vector<vi> a(N,vi(N,-1));
    int x,y,z;
    Rep(i,N){
        Scd(x);
        Rep(j,x){
            Scd2(y,z);
            y--;
            a[i][y] = z;
        }
    }

    int ans = 0;
    int cnt = 0;
    bool ok = false;
    Rep(bi,(1<<N)){
        ok = true;
        cnt = 0;
        Rep(i,N){
            if( bi&(1<<i) ){
                cnt++;
                Rep(j,N){
                    if( a[i][j] == -1 ) continue;
                    if( (bi&(1<<j)) != (a[i][j]<<j) ) ok = false;
                }
            }
        }
        if( ok ){
            ans = max(ans,cnt);
        }
    }

    printf ("%d\n", ans );

    return 0;
}

