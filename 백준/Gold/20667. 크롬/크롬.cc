#include <bits/stdc++.h>

class Tab {
public:
    int cpu = 0;
    int memory = 0;
    int priority = 0;
};

std::istream &operator>>( std::istream &is, Tab &t ) {
    is >> t.cpu >> t.memory >> t.priority;
    return is;
}

int main( int argc, char **argv ) {
    std::cin.tie( 0 );
    std::cout.tie( 0 );
    std::ios_base::sync_with_stdio( false );

#ifndef BOJ
    freopen( argv[ 1 ], "r", stdin );
#endif

    std::vector<std::vector<int>> dp( 501, std::vector<int>( 1002, INT_MIN ) ); // [sum of priority][sum of cpu] = max memory
    dp[ 0 ][ 0 ] = 0;

    std::vector<Tab> tabs(1, Tab());

    int N, min_of_cpu, min_of_memory;
    std::cin >> N >> min_of_cpu >> min_of_memory;
    while ( N-- ) {
        Tab t;
        std::cin >> t;
        tabs.push_back( t );
    }

    for ( int i = 0; i < tabs.size(); i++ ) {
        for ( int j = 500; j >= 0; j-- ) {
            for( int k = 1001; k >= 0; k-- ) {
                if ( j + tabs[i].priority > 500) continue;
                // std::cout << __LINE__ << std::endl;
                dp[j + tabs[i].priority][std::min<>(k + tabs[i].cpu,1001)] = std::max( dp[j + tabs[i].priority][std::min<>(k + tabs[i].cpu,1001)], dp[j][k] + tabs[i].memory );
                // std::cout << __LINE__ << std::endl;
            }
        }
    }

    int ans = -1;

    for ( int i = 0; i < 501; i++ ) {
        for ( int j = min_of_cpu; j < 1002; j++ ) {
            if ( dp[i][j] >= min_of_memory){
                if(ans==-1 || ans > i){
                    ans = i;
                }
            }
        }
    }

    std::cout << ans << std::endl;
    
    return 0;
}