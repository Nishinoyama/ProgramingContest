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

struct ST{
    int N;
    vi d;

    void build( int n ){
        N = 1;
        while( N < n ) N += N;
    }

    void init( vi &a ){
        int n = a.size();
        for( int i = 0; i < n; i++ ){
            d[i+N] = a[i];
        }
        for( int i = N-1; i > 0; i-- ){
            d[i] = min( d[i*2], d[i*2+1] );
        }
    }

    void upd( int x, int a ){
        x += N;
        d[x] = a;
        while( x >>= 1 ) d[x] = min( d[x*2], d[x*2+1] );
    }

    int query( int a, int b, int k = 1, int l = 0, int r = -1 ){
        if( r == -1 ) r = N;
        if( a >= r || b <= l ) return INF;
        if( a <= l && b >= r ) return d[k];
        else {
            int ld = query( a,b, k*2  , l,r/2 );
            int rd = query( a,b, k*2+1, r/2+1,r );
            return min( ld, rd );
        }
    }

};

struct BIT{
    int N;
    vi d;
    BIT( int n){
        N = 1;
        while( N < n ) N += N;
        d.assign(N+1,0);
    }
    void add( int x, int a ){
        x++;
        while( x < N+1 ){
            d[x] += a;
            x += ((-x)&x);
        }
    }
    int query( int a ){
        int ret = 0;
        a++;
        while( a ){
            ret += d[a];
            a -= ((-a)&a);
        }
    }
};

int main() {

    char s[123123];
    int K;
    Scs(s);
    Scd(K);
    int N = strlen(s);
    vi S(s,s+N);

    vector<deque<int>> ch(255);
    Rep(i,N) ch[s[i]].push_back(i);

    ST st;
    st.build(N);
    st.init(S);

    BIT bi(N);

    string ans;

    Rep(i,N){
        int li = 0;
        int ri = N;
        int mi;
        while( ri - li >= 1 ){
            mi = (li+ri)/2;
            int k = mi+1-bi.query(mi);
            if( k <= K ) li = mi;
            else ri = mi;
        }
        char hit = st.query(0,mi+1);
        ans.push_back(hit);
        bi.add( ch[hit].front(), 1 );
        st.upd( ch[hit].front(), INF );
        ch[hit].pop_front();
    }


    return 0;
}



