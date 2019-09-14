#include<bits/stdc++.h>
using namespace std;
typedef long long unsigned int ll;

// definition {{{ 1

// scaning {{{ 2
#define Scd(x) scanf("%d", &x)
#define Scd2(x,y) scanf("%d%d", &x, &y)
#define Scd3(x,y,z) scanf("%d%d%d", &x, &y, &z)

#define Scll(x) scanf("%llu", &x)
#define Scll2(x,y) scanf("%llu%llu", &x, &y)
#define Scll3(x,y,z) scanf("%llu%llu%llu", &x, &y, &z)

#define Scc(c) scanf("%c", &c);
#define Scs(s) scanf("%s", s);
#define Scstr(s) scanf("%s", &s);
// }}} 2

// constants {{{ 2
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
// }}} 2

// systems {{{ 2
#define Rep(x,y) for(int x = 0; x < y; x++)
#define Repe(x,y,z) for(int x = z; x < y; x++)
// }}} 2

// output {{{ 2
#define YesNo(a) (a)?printf("Yes\n"):printf("No\n");
// }}} 2

// }}} 1

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


/*
 * UFinit(n) := initialize Union Find with n UFs( must operate )
 * UFpare[] = root of node
 * UFrank[] = rank of root
 * UFroot(x) := return root of node
 * UFunion(x,y) := unite two root in a root
 * UFsame(x,y) := return two root is same
 */
// }}}

int main() {

    int n,k;
    Scd2(n,k);
    UFinit(3*n);

    int a,b,c;
    int ans = 0;
    Rep(i,k){
        Scd3(a,b,c);
        if( max(b,c) > n ){
            ans++;
            //printf ("doubt!\n");
            continue;
        }
        if( a == 1 ){
            if( UFsame(b , c+n ) || UFsame(b , c+2*n )){
                ans++;
                //printf ("doubt!\n");
                continue;
            }
            UFunion(b,c);
            UFunion(b + n,c + n);
            UFunion(b + 2*n,c + 2*n);
        }
        if( a == 2 ){
            if( UFsame(b , c) || UFsame(b , c+2*n )){
                ans++;
                //printf ("doubt!\n");
                continue;
            }
            UFunion(b,c + n);
            UFunion(b + n,c + 2*n);
            UFunion(b + 2*n,c);
        }
    }

    printf ("%d\n", ans);




    return 0;
}

