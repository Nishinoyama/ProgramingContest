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

// {{{ Union Find  to use UFinit(n) for 0-n UFs

int UFpare[190004];
int UFrank[190004];
void UFinit(int n){
    for (int i = 0; i <= n; i++) {
        UFpare[i] = i;
        UFrank[i] = 0;
    }
}
int UFroot( int x ){
    if( UFpare[x] == x ) return x;
    else{
        return UFpare[x] = UFroot(UFpare[x]);
    }
}
void UFunion( int x , int y ){
    x = UFroot(x);
    y = UFroot(y);
    if( x == y ) return;
    if( UFrank[x] < UFrank[y] ){
        UFpare[x] = y;
    }else{
        UFpare[y] = x;
        if ( UFrank[x] == UFrank[y] ) UFrank[x]++;
    }
}
bool UFsame( int x, int y){
    return UFpare[x] == UFpare[y];
}

// }}}

int main() {

    int N,M,T;
    Scd3(N,M,T);

    vi x(M),y(M);
    Rep(i,M){
        Scd2(x[i],y[i]);
        x[i]--,y[i]--;
    }

    UFinit(M+2);

    vi v(M,0);
    RRep(i,M){
        if( UFsame(y[M-1],y[i]) ) v[i] = 'v'; else v[i] = '^';
        UFunion(x[i],y[i]);
    }

    bool ans = true;
    Rep(i,N-1){
        ans = ans && UFsame(i,i+1);
    }

    if( ans ) {
        Rep(i,M) printf ("%c", v[i] );
        printf ("\n");
    }else{
        printf ("%d\n", -1 );
    }

    return 0;
}

