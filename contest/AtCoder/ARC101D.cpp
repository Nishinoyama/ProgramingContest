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

// {{{ BIT
struct BIT{
    vector<int> data;
    int leng;
    BIT( int n ){
        init(n);
    }
    void init(int n){
        leng = n;
        data.assign(n,0);
        for(int i = 0; i < n; i++ ){
            data[i] = 0;
        }
    }
    int sum(int i){
        int s = 0;
        for( ; i>0; i -= i & -i ){
            s += data[i];
        }
        return s;
    }
    void add(int i, int x){
        for( ; i<=leng ; i += i & -i ){
            data[i] += x;
        }
    }
};
// }}}

int main() {

    int N;
    Scd(N);
    vi a(N);
    Rep(i,N) Scd(a[i]);
    vi ca(a.begin(),a.end());
    sort(ca.begin(),ca.end());

    int l = 0;
    int r = N;
    int cc;
    int c;
    vi b(N+1);
    BIT bit(N*2+20);
    // (l,r]
    while( r-l > 1 ){
        cc = (r+l)/2;
        c = ca[cc];
        Rep(i,N) b[i+1] = a[i]>=c?1:-1;
        Rep(i,N){
            b[i+1] += b[i];
        }
        ll sum = 0;
        bit.init(N*2+20);
        Rep(i,N+1){
            sum += bit.sum(b[i]+N+3);
            bit.add(b[i]+N+3,1);
        }
        // printf ("%d:%lld\n", c, sum );
        if( sum >= (1ll*N*(N+1)/2+1)/2 ) l = cc;
        else r = cc;
    }

    printf ("%d\n", ca[l] );

    return 0;
}

// 3
//   -1  1 -1
// 0 -1  0 -1
