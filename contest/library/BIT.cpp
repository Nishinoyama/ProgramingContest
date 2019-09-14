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

// {{{ BinaryIndexedTree

// {{{実装
struct BIT{
    int data[200000];
    int leng;
    BIT( int n ){
        init(n);
    }
    void init(int n){
        this->leng = n;
        for(int i = 0; i < n; i++ ){
            this->data[i] = 0;
        }
    }
    int sum(int i){
        int s = 0;
        for( ; i>0; i -= i & -i ){
            s += this->data[i];
        }
        return s;
    }
    void add(int i, int x){
        for( ; i<=this->leng ; i += i & -i ){
            this->data[i] += x;
        }
    }
};
// }}}

// {{{ 説明
/*
BIT.data[1,n] : data
BIT.leng : quantity of data
BIT.init(n) : YES
BIT.sum(a) : sum of data[1,a]
BIT.add(i,x) : add data[i] with x
*/
// }}}

// }}}

int main() {

    int n,a;
    Scd(n);
    BIT b(n);
    b.init(n);
    Repe(i,n+1,1){
        Scd(a);
        b.add(i,a);
    }
    Scd(n);
    Rep(i,n){
        Scd(a);
        printf ("%d\n", b.sum(a));
    }

    return 0;
}

