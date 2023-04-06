#include <bits/stdc++.h>

std::pair<int, int> log2(int n) {
    int i = 0;
    while(!(n&1)) {
        n >>= 1;
        i++;
    }
    return {i, n};
}

std::vector<int> bake( int N, bool is_K_even){
    std::vector<int> v(N, 0);

    for( int x = 1; x<N; x++){
        std::set<int> s;

        s.insert( v[x-1] );

        if( (x%2==0) && !is_K_even ) s.insert( v[x/2] );
        else if( (x%2==0) && is_K_even ) s.insert( 0 );

        int mex = 0;
        while( s.find(mex) != s.end() ) mex++;

        v[x] = mex;
    }

    return v;
}

int grundy(int N, bool is_K_even){
    if(is_K_even){
        if(N==0) return 0;
        if(N==1) return 1;
        if(N==2) return 2;
        else return !(N&1);
        return (N&1);
    }else{
        if(N==0) return 0;
        else if(N==1) return 1;
        else if(N==2) return 0;
        else if(N==3) return 1;
        else if(N&1) return 0;

        auto [i, n] = log2(N);
        if(i&1){
            return ((n==3) ? 2 : 1);
        }else{
            return ((n==1 || (n%2==1 && n>=5)) ? 2 : 1);
        }
    }
}

int main( int argc, char *argv[] ) {
#ifndef BOJ
    freopen( argv[ 1 ], "r", stdin );
#endif

    int N, K;
    std::cin >> N >> K;

    int ans = 0;
    int x;

    while(N--){
        std::cin >> x;
        ans ^= grundy(x, K%2==0);
    }

    std::cout << (ans ? "Kevin" : "Nicky") << std::endl;

    return 0;
}