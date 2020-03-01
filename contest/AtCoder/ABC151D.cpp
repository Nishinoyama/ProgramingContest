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

int H,W;
char s[123][123];
int used[123][123];

int main() {

    Scd2(H,W);

    Rep(i,H) Scs(s[i]);

    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    int ans = 0;
    deque<pii> q;
    Rep(h,H) Rep(w,W){
        if( s[h][w] == '#' ) continue;
        Rep(i,H) Rep(j,W) used[i][j] = -1;
        used[h][w] = 0;
        q.push_back({h,w});
        while( q.size() ){
            pii tt = q.front(); q.pop_front();
            int hi = tt.first;
            int wi = tt.second;
            int dist = used[hi][wi];
            ans = max(dist,ans);

            Rep(di,4){
                int hhi = hi+dx[di];
                int wwi = wi+dy[di];
                if( hhi >= H || hhi < 0 ) continue;
                if( wwi >= W || wwi < 0 ) continue;
                if( used[hhi][wwi] != -1 ) continue;
                if( s[hhi][wwi] != '.' ) continue;
                used[hhi][wwi] = dist+1;
                q.push_back({hhi,wwi});
            }

        }
    }

    printf ("%d\n", ans );

    return 0;
}

