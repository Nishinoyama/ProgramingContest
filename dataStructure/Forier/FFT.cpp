// #include<bits/stdc++.h>
#include<cstdio>
#include<ccomplex>
#include<vector>
#include<cmath>

using namespace std;
using comp = complex<double>;
using compPol = vector<comp>;
using FTPol = vector<comp>;
// Polynomial

#define PI 3.14159265358979

FTPol FFT( compPol& a ){
    int n = a.size();
    FTPol f(n,comp(0,0));
    for( int i = 0; i < n; i++ ){
        comp zeta( cos(PI*2*i/n), sin(PI*2*i/n) );
        comp zetabase( 1.0,0 );
        for( int j = 0; j < n; j++ ){
            f[i] += a[j] * zetabase;
            zetabase *= zeta;
        }
    }
    return fgit;
}

compPol iFFT( FTPol& a ){
    int n = a.size();
    FTPol f(n,comp(0,0));
    for( int i = 0; i < n; i++ ){
        comp zeta( cos(PI*2*i/n), -sin(PI*2*i/n) );
        comp zetabase( 1.0,0 );
        for( int j = 0; j < n; j++ ){
            f[i] += a[j] * zetabase;
            zetabase *= zeta;
        }
        f[i] /= n;
    }
    return f;
}

int main() {

    int N;
    scanf("%d", &N );
    int k = 1;
    while( N >= k ) k <<= 1;
    k <<= 1;

    compPol g(k);
    compPol h(k);
    int a,b;
    for( int i = 0; i < N; i++ ){
        scanf("%d %d", &a, &b );
        g[i+1] = comp(a,0);
        h[i+1] = comp(b,0);
    }

    FTPol fg = FFT(g);
    FTPol fh = FFT(h);

    FTPol fgh(k);
    for( int i = 0; i < k; i++ ){
        fgh[i] = fg[i] * fh[i];
    }

    compPol ifgh = iFFT(fgh);
    // for (int i = 0; i < k; i++)
    // {
    //     printf("%1.9f, %1.9f\n", real(ifgh[i]), imag(ifgh[i]) );
    // }
    // printf("\n");

    for (int i = 1; i <= N*2; i++)
    {
        printf("%d\n", (int)(real(ifgh[i]) + 0.5) );
    }



    return 0;
}

