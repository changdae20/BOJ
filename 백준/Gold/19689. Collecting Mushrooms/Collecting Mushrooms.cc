#include <bits/stdc++.h>

int main( int argc, char *argv[] ) {
    std::cin.tie( 0 );
    std::ios::sync_with_stdio( false );
    std::cout.tie( 0 );
#ifndef BOJ
    freopen( argv[ 1 ], "r", stdin );
#endif
    int R, C, D, K;

    std::cin >> R >> C >> D >> K;
    char c;

    std::vector<std::vector<int>> grid( C + 1, std::vector<int>( R + 1, 0 ) );
    std::vector<std::pair<int, int>> mushrooms;

    for ( int y = 1; y <= R; ++y ) {
        for ( int x = 1; x <= C; ++x ) {
            std::cin >> c;
            if(c== 'M'){
                mushrooms.push_back( std::pair( x, y ) );
            }
            grid[ x ][ y ] = grid[ x - 1 ][ y ] + grid[ x ][ y - 1 ] - grid[ x - 1 ][ y - 1 ] + ( c == 'S' ? 1 : 0 );

        }
    }
    int ans = 0;

    for( auto &[x,y] : mushrooms){
        int x1 = std::max<>(x - D - 1, 0);
        int x2 = std::min<>(x + D, C);
        int y1 = std::max<>(y - D - 1, 0);
        int y2 = std::min<>(y + D, R);
        if((grid[ x2 ][ y2 ] - grid[ x1 ][ y2 ] - grid[ x2 ][ y1 ] + grid[ x1 ][ y1 ])>= K){
            ++ans;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}