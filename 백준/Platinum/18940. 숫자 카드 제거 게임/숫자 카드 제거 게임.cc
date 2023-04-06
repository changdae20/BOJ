#include <bits/stdc++.h>

constexpr std::array<int, 39> period1 = { 0, 1, 1, 2, 0,
                                           3, 1, 1, 0, 3,
                                           3, 2, 2, 4, 0,
                                           5, 2, 2, 3, 3,
                                           0, 1, 1, 3, 0,
                                           2, 1, 1, 0, 4,
                                           5, 2, 7, 4, 0,
                                           1, 1, 2, 0 };

constexpr std::array<int, 34> period2 = { 3, 1, 1, 0, 3,
                                           3, 2, 2, 4, 4,
                                           5, 5, 2, 3, 3,
                                           0, 1, 1, 3, 0,
                                           2, 1, 1, 0, 4,
                                           5, 3, 7, 4, 8,
                                           1, 1, 2, 0 };

std::vector<int> bake( int n, bool save = true ) {
    // check runtime
    auto start = std::chrono::system_clock::now();

    std::vector<int> v( n, 0 );
    v[ 1 ] = 1;
    v[ 2 ] = 1;
    v[ 3 ] = 2;

    // fill the array with mex (grundy number)
    for ( int x = 1; x < n; ++x ) {
        std::set<int> s;

        s.insert( v[ x - 2 ] );

        for ( int i = 0; i <= x - 3; ++i ) {
            s.insert( v[ i ] ^ v[ x - 3 - i ] );
        }

        int mex = 0;
        while ( s.find( mex ) != s.end() ) {
            mex++;
        }
        v[ x ] = mex;
    }

    // save to file as mex_k.txt
    if ( save ) {
        std::ofstream ofs( "mex.txt" );
        for ( int x = 0; x < n; ++x ) {
            ofs << std::setw( 5 ) << v[ x ] << std::endl;
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

bool grundy( int x ) {
    return ( x > 38 ? period2[ ( x - 39 ) % 34 ] : period1[ x ] );
}

void check( int n ) {
    auto v = bake( n );
    for ( int x = 1; x < n; ++x ) {
        if ( grundy( x ) != static_cast<bool>(v[ x ]) ) {
            std::cout << "Error at x : " << x << std::endl;
            return;
        }
    }
}

int main() {
    std::cin.tie( nullptr );
    std::ios::sync_with_stdio( false );
    std::cout.tie( nullptr );

    int n,T;
    std::cin >> T;
    while ( T-- ) {
        std::cin >> n;
        std::cout << ( grundy( n ) ? "Yuto" : "Platina" ) << '\n';
    }

    return 0;
}