#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct Tree{
    int N;
    int root;
    vector<int> pare;
    vector<vector<int>> child;
    Tree( int r, vector<vector<int>>& e ){
        root = r;
        pare.assign(N,-1);

        stack<int> s;
        s.push(r);
        while( s.size() ){
            int from = s.top();
            s.pop();
            for
        }
    }
};

int main() {

    int N;
    scanf("%d", &N );

    Rep(i,N-1){
        scanf("%d %d", &x, &y );
    }

    return 0;
}



