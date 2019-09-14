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

const long long int mod = 1000000007;

// PowMod( base, index, modulo) return base ** index % modulo {{{
// PowMod = base ** index % mod ( natural numbers )
inline constexpr long long int PowMod( long long int base, long long int index, long long int modulo = mod ){
    if( index == 0 ) return 1;
    // O( log(index) )
    if( index % 2 ){
        return base * PowMod(base, index - 1, modulo) % modulo;
    }else{
        long long int Phalf = index / 2;
        long long int half = PowMod(base, Phalf, modulo);
        return half * half % modulo;
    }
}
// }}}

int main() {

    int N;
    Scd(N);

    vl dp(9);
    vl dpl(9);
    dp[7] = 1;
    // dp[i] = i面待ち
    // dp[i+4] = i面待ち( symetroic )
    // dp[5,6] := 0

    Rep(i,N){
        dpl[0] = PowMod( dp[1], 1 )*3 + PowMod( dp[1], 2 )*3 + PowMod( dp[1], 3 ) - dp[1];
        dpl[1] = PowMod( dp[2], 1 )*3 + PowMod( dp[2], 2 )*3 + PowMod( dp[2], 3 );
        dpl[2] = 0 + dp[3]*6 + dp[7]*6;
        dpl[3] = 0 + PowMod( dp[3] + dp[7] , 2 )*3 + PowMod( dp[3] + dp[7] , 3 ) - dp[3] - dp[7];
        dpl[4] = 1 + dp[1];
        dpl[5] = 0;
        dpl[6] = 0;
        dpl[7] = 0 + dp[3] + dp[7];

        dp[0] = dpl[0] % mod;
        dp[1] = dpl[1] % mod;
        dp[2] = dpl[2] % mod;
        dp[3] = dpl[3] % mod;
        dp[4] = dpl[4] % mod;
        dp[5] = dpl[5] % mod;
        dp[6] = dpl[6] % mod;
        dp[7] = dpl[7] % mod;
    }

    printf ("%lld\n", (dp[0]+dp[1]+dp[2]+dp[3]+dp[4]+dp[5]+dp[6]+dp[7])%mod );

    return 0;
}



