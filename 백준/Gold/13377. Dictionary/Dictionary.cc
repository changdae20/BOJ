#include <bits/stdc++.h>

template<int N>
struct Factorial{
    static const int value = N * Factorial<N-1>::value;
};

template<>
struct Factorial<0>{
    static const int value = 1;
};

int main( int argc, char **argv ) {
    std::cin.tie( 0 );
    std::cout.tie( 0 );
    std::ios_base::sync_with_stdio( false );

#ifndef BOJ
    freopen( argv[ 1 ], "r", stdin );
#endif

    int T;
    std::cin >> T;

    std::string s;

    std::array<int, 10> Factorials = { Factorial<0>::value, Factorial<1>::value, Factorial<2>::value, Factorial<3>::value, Factorial<4>::value, Factorial<5>::value, Factorial<6>::value, Factorial<7>::value, Factorial<8>::value, Factorial<9>::value };

    while(T--){
        std::cin >> s;
        int ans = 1;
        for(auto it = s.begin(); it != s.end(); it++){
            ans += Factorials[std::distance(it, s.end())-1] * (*it - 'a');
            for(auto it2 = std::next(it,1); it2 != s.end(); it2++){
                if(*it < *it2){
                    (*it2)--;
                }
            }
        }
        std::cout << ans << std::endl;
    }

    return 0;
}