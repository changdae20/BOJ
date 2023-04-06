#include <bits/stdc++.h>

constexpr std::array<bool, 45> period1 = { false, true, true, false, false,
                                           false, true, false, false, false,
                                           true, false, false, false, false,
                                           false, true, false, false, false,
                                           false, false, true, false, false,
                                           false, true, false, false, false,
                                           true, false, false, false, false,
                                           false, true, false, false, false,
                                           true, false, false, false, true }; // 1,2,6,10,16,22,26,30,36,40,44

constexpr std::array<bool, 34> period2 = { false, false, false, false, false,
                                           false, false, false, false, false,
                                           false, true, false, false, false,
                                           true, false, false, false, true,
                                           false, false, false, false, false,
                                           false, false, false, false, true,
                                           false, false, false, true }; // 11,15,19,29,33

std::vector<std::vector<int>> bake( int n, bool save = true ) {
    // check runtime
    auto start = std::chrono::system_clock::now();

    std::vector<std::vector<int>> v( n, std::vector<int>( n, 0 ) );

    // fill the array with mex (grundy number)
    for ( int y = 1; y < n; ++y ) {
        for ( int x = 1; x < n; ++x ) {
            std::set<int> s;

            // check row
            for ( int i = 2; i <= x - 1; ++i ) {
                s.insert( v[ i - 1 ][ y ] ^ v[ x - i ][ y ] );
            }

            // check column
            for ( int i = 2; i <= y - 1; ++i ) {
                s.insert( v[ x ][ i - 1 ] ^ v[ x ][ y - i ] );
            }

            int mex = 0;
            while ( s.find( mex ) != s.end() ) {
                mex++;
            }
            v[ x ][ y ] = mex;
        }
    }

    // save to file as mex_k.txt
    if ( save ) {
        std::ofstream ofs( "mex.txt" );
        for ( int y = 0; y < n; ++y ) {
            for ( int x = 0; x <= y; ++x ) {
                ofs << std::setw( 5 ) << v[ x ][ y ];
            }
            ofs << std::endl;
        }
        std::cout << "Saved as "
                  << "mex.txt" << std::endl;
    }

    // check runtime
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Elapsed time: " << elapsed_seconds.count() << "s" << std::endl;

    return v;
}

int grundy( int x, int y ) { // 0~44 이후로 45부터는 주기34
    if ( x <= 44 && y <= 44 )
        return period1[ x ] && period1[ y ];
    else if ( x > 44 && y > 44 )
        return period2[ ( x - 45 ) % 34 ] && period2[ ( y - 45 ) % 34 ];
    else
        return period1[ std::min<>( x, y ) ] && period2[ ( std::max( x, y ) - 45 ) % 34 ];
}

void check( int n ) {
    auto v = bake( n );
    for ( int x = 1; x < n; ++x ) {
        for ( int y = 1; y < n; ++y ) {
            if ( static_cast<bool>( grundy( x, y ) ) == static_cast<bool>( v[ x ][ y ] ) ) {
                std::cout << "Error at (" << x << ", " << y << ")" << std::endl;
                return;
            }
        }
    }
}

int main() {
    int N, M;
    std::cin >> N >> M;
    std::cout << ( grundy( N, M ) ? "hs" : "sh" ) << std::endl;

    return 0;
}