#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll mod = 1000000007;

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
// modint {{{

struct modint{
    long long int a;
    inline constexpr modint( long long int x = 0 ) noexcept : a(x % mod) {}
    inline constexpr long long int &value() noexcept { return a; }
    inline constexpr const long long int &value() const noexcept { return a; }
    inline constexpr modint operator+(const modint rhs) const noexcept{ return modint(*this) += rhs; }
    inline constexpr modint operator+(const int rhs) const noexcept{ return modint(*this) += rhs; }
    inline constexpr modint operator+(const long long int rhs) const noexcept{ return modint(*this) += rhs; }
    inline constexpr modint operator-(const modint rhs) const noexcept{ return modint(*this) -= rhs; }
    inline constexpr modint operator-(const int rhs) const noexcept{ return modint(*this) -= rhs; }
    inline constexpr modint operator-(const long long int rhs) const noexcept{ return modint(*this) -= rhs; }
    inline constexpr modint operator*(const modint rhs) const noexcept{ return modint(*this) *= rhs; }
    inline constexpr modint operator*(const int rhs) const noexcept{ return modint(*this) *= rhs; }
    inline constexpr modint operator*(const long long int rhs) const noexcept{ return modint(*this) *= rhs; }
    inline constexpr modint operator/(const modint rhs) const noexcept{ return modint(*this) /= rhs; }
    inline constexpr modint operator/(const int rhs) const noexcept{ return modint(*this) /= rhs; }
    inline constexpr modint operator/(const long long int rhs) const noexcept{ return modint(*this) /= rhs; }
    inline constexpr modint operator+=(const modint rhs) noexcept{ a += rhs.a; if( a >= mod ) a -= mod; return *this; }
    inline constexpr modint operator-=(const modint rhs) noexcept{ a -= rhs.a; if( a < 0 ) a += mod; return *this; }
    inline constexpr modint operator*=(const modint rhs) noexcept{ a = a * rhs.a % mod ;  return *this; }
    inline constexpr modint operator/=(const modint rhs) noexcept{ a = a * PowMod(rhs.a,mod-2) % mod; return *this; }
};

// }}}

int main() {

    int D;
    Scd(D);

    char N[10020];
    Scs(N);

    int n = strlen(N);


    static modint dp[10002][100][2] = {};
    // dig / mul / max

    dp[0][0][1] = 1;

    Rep(ni,n){
        Rep(di,D){
            Rep(ki,10){
                dp[ni+1][(di+ki)%D][0] += dp[ni][di][0];
            }
            Rep(ki,N[ni]-'0'+1){
                dp[ni+1][(di+ki)%D][1&&ki==N[ni]-'0'] += dp[ni][di][1];
            }
        }
    }

    printf ("%lld\n", dp[n][0][1] + dp[n][0][0] - 1 );


    return 0;
}



