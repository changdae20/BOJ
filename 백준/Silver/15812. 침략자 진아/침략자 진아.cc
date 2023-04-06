#include <bits/stdc++.h>

std::vector<std::array<int, 2>> nC2(int n) {
    std::vector<std::array<int, 2>> res;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            res.push_back({i, j});
        }
    }
    return res;
}

int cost( const std::pair<int, int> &pt1, const std::pair<int, int> &pt2, const std::vector<std::pair<int,int>> &ones){
    int cost = 0;
    for( auto &[x, y] : ones){
        cost = std::max( cost, std::min( std::abs( x - pt1.first) + std::abs( y - pt1.second), std::abs( x - pt2.first) + std::abs( y - pt2.second)));
    }
    return cost;
}
int main() {
    std::cin.tie( nullptr );
    std::ios::sync_with_stdio( false );
    std::cout.tie( nullptr );
    int rows, cols;
    std::cin >> rows >> cols;
    char c;
    std::vector<std::pair<int,int>> ones;
    std::vector<std::pair<int,int>> zeros;
    
    for( int y = 0; y < rows; ++y ) {
        for( int x = 0; x < cols; ++x ) {
            std::cin >> c;
            if( c == '1' ) {
                ones.emplace_back( x, y );
            } else {
                zeros.emplace_back( x, y );
            }
        }
    }

    int min_cost = INT_MAX;
    
    for( auto &[idx1, idx2] : nC2( zeros.size() ) ) {
        min_cost = std::min( min_cost, cost( zeros[idx1], zeros[idx2], ones));
    }

    std::cout << min_cost << std::endl;
    return 0;
}