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

    int N,M;
    Scd2(N,M);

    bool e[701][701] = {};

    int x,y;
    Rep(i,M){
        Scd2(x,y);
        x--,y--;
        e[x][y] = true;
        e[y][x] = true;
    }
    Rep(i,N) e[i][i] = true;

    bool biparitite = true;
    stack<int> st;
    vi id(N,-1);
    vi col(N,0);
    vii sum;
    int tid = 0;
    Rep(i,N){
        if( id[i] == -1 ){
            pii cnt(0,0);
            st.push(i);
            id[i] = tid;
            col[i] = 1;
            while(st.size()){
                int from = st.top();
                int c = col[from];
                if( c>0 ) cnt.first++;
                else cnt.second++;
                st.pop();
                Rep(to,N){
                    if( !e[from][to] ){
                        if( c == col[to] ) biparitite = false;
                        if( id[to] != -1 ) continue;
                        st.push(to);
                        id[to] = tid;
                        col[to] = -c;
                    }
                }
            }
            tid++;
            sum.push_back(cnt);
        }
    }

    if( !biparitite ) {
        printf ("%d\n", -1 );
        return 0;
    }

    static bool dp[701][701] = {};
    dp[0][0] = true;
    for( pii s : sum ){
        RRep(i,N+1) RRep(j,N+1){
            if( dp[i][j] ){
                int ii,jj;
                ii = i + s.first; jj = j + s.second;
                if( ii <= N && jj <= N ) dp[ii][jj] = true;
                ii = i + s.second; jj = j + s.first;
                if( ii <= N && jj <= N ) dp[ii][jj] = true;
            }
        }
    }

    ll ans = -1;
    Rep(i,N+1){
        if( dp[i][N-i] ) ans = max( ans, i*(N-i) );
    }

    printf ("%lld\n", N*(N-1)/2-ans );


    return 0;
}

