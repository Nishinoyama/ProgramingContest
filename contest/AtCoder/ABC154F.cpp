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
// CombMod( n, r, modulo ) return nCr % modulo {{{
// CombMod(ination) = nCr % mod ( natural number )
inline constexpr long long int CombMod( long long int n, long long int r, long long int modulo = mod){
    if( n < r ) return CombMod(r,n,modulo);
    long long int Upper = 1;
    long long int Lower = 1;
    for(long long int i = 0; i < r; i++){
        Upper = Upper * (n-i) % modulo;
        Lower = Lower * (i+1) % modulo;
    }
    // Return (Upper / Lower)
    long long int ret = Upper * PowMod(Lower,modulo-2,modulo) % modulo;
    return ret;
}
// }}}
// FactMod( n, modulo ) return n! % modulo {{{
// Fact(orial) = n! % mod ( natural number )
inline constexpr long long int Fact( long long int n, long long int modulo = mod){
    long long int Upper = 1;
    for(long long int i = 0; i < n; i++){
        Upper = Upper * (n-i) % modulo;
    }
    return Upper;
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

    int l1,r1,l2,r2;

    Scd2(l1,l2);
    Scd2(r1,r2);
    l1--,l2--;

    int N = 1e6;
    int M = 1e6;
    vector<modint> f(N*3+1);
    vector<modint> fr(N*3+1);
    f[0] = 1;
    Rep(i,N*3) f[i+1] = f[i]*(i+1);
    Rep(i,N*3+1) fr[i] = modint(1)/f[i];
    modint ans1 = 0;
    modint ans2 = 0;
    modint ans3 = 0;
    modint ans4 = 0;

    M = max(r1,r2); N = min(r1,r2);
    Repe(i,N+2,1){
        ans1 += f[M+i] * fr[M] * fr[i];
    }
    M = max(l1,r2); N = min(l1,r2);
    Repe(i,N+2,1){
        ans2 += f[M+i] * fr[M] * fr[i];
    }
    M = max(r1,l2); N = min(r1,l2);
    Repe(i,N+2,1){
        ans3 += f[M+i] * fr[M] * fr[i];
    }
    M = max(l1,l2); N = min(l1,l2);
    Repe(i,N+2,1){
        ans4 += f[M+i] * fr[M] * fr[i];
    }

    printf ("%lld\n", ans1-ans2-ans3+ans4 );

    return 0;
}
