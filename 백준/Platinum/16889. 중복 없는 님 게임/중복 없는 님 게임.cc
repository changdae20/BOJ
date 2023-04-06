#include <bits/stdc++.h>

std::vector<std::map<int, unsigned long long>> g( 61, std::map<int, unsigned long long>() );

int calc_grundy( int N, unsigned long long history ) {
    // 이미 계산했던 경우
    if ( g[ N ].find( history ) != g[ N ].end() ) {
        return g[ N ][ history ];
    }

    // N개 남았는데 이미 history에 1~N이 다 있는 경우
    if ( history & ( ( 1 << N ) - 1 ) == ( ( 1 << N ) - 1 ) ) {
        return g[ N ][ history ] = 0;
    }

    std::set<int> s;

    for ( int i = 1; i <= N; ++i ) {
        if ( history & ( 1 << ( i - 1 ) ) ) {
            continue;
        }
        s.insert( calc_grundy( N - i, history | ( 1 << ( i - 1 ) ) ) );
    }

    int ret = 0;
    while ( s.find( ret ) != s.end() ) {
        ++ret;
    }

    return g[ N ][ history ] = ret;
}

// 런타임 전의 전처리 결과
std::array<int, 61> grundy = { 0, 1, 1, 2, 2, 2,
                               3, 3, 3, 3, 4,
                               4, 4, 4, 4, 5,
                               5, 5, 5, 5, 5,
                               6, 6, 6, 6, 6,
                               6, 6, 7, 7, 7,
                               7, 7, 7, 7, 7,
                               8, 8, 8, 8, 8,
                               8, 8, 8, 8, 9,
                               9, 9, 9, 9, 9,
                               9, 9, 9, 9, 10,
                               10, 10, 10, 10, 10 };

int main( int argc, char *argv[] ) {
#ifndef BOJ
    freopen( argv[ 1 ], "r", stdin );
#endif

    unsigned long long N;
    std::cin >> N;
    int n;
    unsigned long long ans = 0;
    while(N--){
        std::cin >> n;
        ans ^= grundy[n];
    }
    if(ans){
        std::cout << "koosaga" << std::endl;
    }else{
        std::cout << "cubelover" << std::endl;
    }

    return 0;
}