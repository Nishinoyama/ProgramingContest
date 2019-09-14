#include<bits/stdc++.h>
using namespace std;

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

    modint n(3777);

    n *= 11;


    printf ("%llu\n", n );

    return 0;
}

