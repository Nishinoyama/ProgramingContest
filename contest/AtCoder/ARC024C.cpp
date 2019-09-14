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

namespace std{
    struct lang{
        static const int n = 30;
        vi c;
        lang(){ c.resize(n); };
        bool operator< ( const lang &b ) const{
            Rep(i,n) if( c[i] < b.c[i] ) return true; else if( c[i] > b.c[i] ) return false;
            return false;
        }
        bool operator== ( const lang &b ) const{
            bool same = true;
            Rep(i,n) same = same && c[i] == b.c[i];
            return same;
        }
        void cha( char t, int x = 1 ){
            c[t-'a'] += x;
        }
        void dump() const{
            Rep(i,n){
                printf ("%d ", c[i] );
            }
            printf ("\n");
        }
    };

    // template <>
    //     struct less<lang> {
    //         bool operator() ( const lang &x, const lang &y ) const {
    //             bool bigger = true;
    //             Rep(i,30) bigger = bigger && x.c[i] < y.c[i];
    //             return bigger;
    //         }
    //     };
}

int main() {

    int N,K;
    Scd2(N,K);

    char s[111111];
    Scs(s);

    set<lang> ls;
    deque<lang> ld;
    lang lg;
    Rep(i,K) lg.cha(s[i]);
    ld.push_back(lg);

    bool ans = false;
    Repe(i,N,K){
        lg.cha(s[i]);
        lg.cha(s[i-K],-1);
        ld.push_back(lg);
        while( ld.size() > K ) ls.insert(ld.front()), ld.pop_front();
        if( ls.find(lg) != ls.end() ) ans = true;
    }

    printf ("%s\n", ans ? "YES" : "NO" );

    return 0;
}



