#include <algorithm>
#include <iostream>
#include <vector>

bool is_4_body( std::vector<int> &v ) {                                     // 재귀적으로 남은 패들이 몸통을 이룰 수 있는지 검사
    if ( std::none_of( v.begin(), v.end(), []( int &n ) { return n; } ) ) { // terminate condition : 하나도 안남았을 때
        return true;
    }

    // 심심해서 그냥 1~9 for문 돌면 될 거를 find_if로 for문 돌려봤다
    for ( auto it = std::find_if( v.begin(), v.end(), []( int &n ) { return n >= 3; } ); it != v.end(); it = std::find_if( std::next( it, 1 ), v.end(), []( int &n ) { return n >= 3; } ) ) { // 똑같은 패 3장으로 몸통 만들기
        ( *it ) -= 3;
        if ( is_4_body( v ) ) {
            ( *it ) += 3;
            return true;
        }
        ( *it ) += 3;
    }

    // 이건 귀찮아서 그냥 2~8로 for문 돌림
    for ( int i = 2; i <= 8; i++ ) {
        if ( v[ i - 1 ] && v[ i ] && v[ i + 1 ] ) { // 연속한 3개가 다 1개이상 패가 있다면
            v[ i - 1 ] -= 1;
            v[ i ] -= 1;
            v[ i + 1 ] -= 1;
            if ( is_4_body( v ) ) {
                v[ i - 1 ] += 1;
                v[ i ] += 1;
                v[ i + 1 ] += 1;
                return true;
            }
            v[ i - 1 ] += 1;
            v[ i ] += 1;
            v[ i + 1 ] += 1;
        }
    }
    return false;
}

bool is_valid( std::vector<int> &v ) { // 1 머리 + 4몸통 or 7머리
    // 7머리 이려면 count가 2인게 총 7가지 여야함.
    if ( std::count( v.begin(), v.end(), 2 ) == 7 ) {
        return true;
    }

    // 1 머리 + 4 몸통 구조?
    for ( int i = 1; i <= 9; i++ ) {
        if ( v[ i ] >= 2 ) {
            v[ i ] -= 2;
            if ( is_4_body( v ) ) {
                v[ i ] += 2;
                return true;
            }
            v[ i ] += 2;
        }
    }

    return false;
}
int main( int argc, char *argv[] ) {
#ifndef BOJ
    freopen( argv[ 1 ], "r", stdin );
#endif

    int N = 13;
    std::vector<int> v( 10, 0 );
    int i;
    while ( N-- ) {
        std::cin >> i;
        v[ i ] += 1;
    }

    int total_ans = 0;
    for ( i = 1; i <= 9; ++i ) { // 하나씩 추가해보면서 valid한지 검사
        if ( v[ i ] >= 4 )
            continue; // 이미 4장이 있으면 추가 불가능, continue
        v[ i ] += 1;
        if ( is_valid( v ) ) {
            ++total_ans;
            std::cout << i << " ";
        }
        v[ i ] -= 1;
    }
    if ( !total_ans ) {
        std::cout << -1;
    }
    std::cout << std::endl;

    return 0;
}