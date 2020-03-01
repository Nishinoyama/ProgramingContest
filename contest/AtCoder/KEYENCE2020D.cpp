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

int popn( int B ){
    int cnt = 0;
    while(B){
        B -= (-B)&B;
        cnt++;
    }
    return cnt;
}

int N;

int swapn( vii& a ){
    int ret = 0;
    vi cnt(51,0);
    Rep(i,N){
        Repe(j,N,a[i].second){
            ret += cnt[j];
        }
        cnt[a[i].second]++;
    }
    return ret;
}

int main() {

    Scd(N);
    vi a(N),b(N);
    Rep(i,N){
        Scd(a[i]);
    }
    Rep(i,N){
        Scd(b[i]);
        if( i%2 ) swap(a[i],b[i]);
    }

    int B = 1<<N;
    int ans = INF;
    vii aa(N/2+1);
    vii bb(N/2);
    vii cc(N);
    bool ok;

    Rep(bi,B){
        if( popn(bi) != (N+1)/2 ) continue;
        aa.clear();
        bb.clear();
        cc.clear();
        Rep(i,N) if( (bi)&(1<<i)  ) aa.push_back({a[i],i});
        Rep(i,N) if( !(bi&(1<<i)) ) bb.push_back({b[i],i});
        sort(aa.begin(),aa.end());
        sort(bb.begin(),bb.end());
        Rep(i,N){
            cc[i] = (i%2?bb:aa)[i/2];
        }
        ok = true;
        Rep(i,N-1){
            if( cc[i].first > cc[i+1].first ) ok = false;
        }
        if( !ok ) continue;
        else{
            ans = min( ans, swapn(cc) );
        }
    }

    if( ans == INF ) ans = -1;
    printf ("%d\n", ans );


    return 0;
}

