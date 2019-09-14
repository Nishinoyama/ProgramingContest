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

    vector<vi> a(N,vi(N, -1 ));
    vi b(N,0);
    set<pair<int,int> > c;
    set<pair<int,int> > d;
    Rep(i,N) Rep(k,N-1) Scd(a[i][k]) , a[i][k]--;

    Rep(i,N) {
        if( a[a[i][0]][0] == i ){
            int x = min( (int)i, a[i][0] );
            int y = max( (int)i, a[i][0] );
            c.insert( { x,y } );
        }
    }

    int ans = 0;
    int cnt = 0;

    while( c.size() ){
        ans++;
        for( auto it = c.begin(); it != c.end(); it++ ){
            cnt++;
            int f = it->first;
            int g = it->second;
            b[f]++;
            b[g]++;
            // printf ("%d,%d[%d],%d[%d]\n", ans ,f , b[f] ,g , b[g] );
            if( f >= 0 && b[f] <= N-2 ){
                int ff = a[f][b[f]];
                if( a[ff][b[ff]] == f ){
                    int x = min( f, ff );
                    int y = max( f, ff );
                    d.insert( { x,y } );
                }
            }
            if( g >= 0 && b[g] <= N-2 ){
                int gg = a[g][b[g]];
                if( a[gg][b[gg]] == g ){
                    int x = min( g, gg );
                    int y = max( g, gg );
                    d.insert( { x,y } );
                }
            }
        }
        c.clear();
        for( auto it = d.begin(); it != d.end(); it++ ){
            c.insert( { it->first, it->second } );
        }
        d.clear();
    }

    printf ("%d\n", cnt == N*(N-1)/2 ? ans : -1 );

    return 0;
}



