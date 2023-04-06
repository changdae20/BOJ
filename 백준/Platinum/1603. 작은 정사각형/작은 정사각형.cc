#include <bits/stdc++.h>

std::map<std::pair<int, int>, int> cache;

int grundy( std::vector<std::vector<char>> &board, int start, int length ) {
    if ( length == 0 )
        return 0;
    if ( start < 0 || start >= board.size())
        return 0;
    if ( auto it = cache.find( std::pair( start, length ) ); it != cache.end() )
        return it->second;

	std::set<int> s;
    for ( int x = start; x < start + length; ++x ) {
        if( board[x][0] == '.' && board[x][1] == '.' ){
            s.insert(grundy(board, start, x - start) ^ grundy(board, x + 1, length - x + start - 1) ^ 1);
        }else if( board[x][0] == '.' || board[x][1] == '.' ){
            s.insert(grundy(board, start, x - start) ^ grundy(board, x + 1, length - x + start - 1));
        }

        if( (x < start + length - 1) && board[x][0] == '.' && board[x][1] == '.' && board[x+1][0] == '.' && board[x+1][1] == '.'){
            s.insert(grundy(board, start, x - start) ^ grundy(board, x+2, length - x + start -2));
        }
    }

    int mex = 0;
    while(s.count(mex)) ++mex;
    cache[std::pair(start, length)] = mex;

    return mex;
}

int main(int argc, char* argv[]){

    std::cin.tie( nullptr );std::cout.tie( nullptr );
    std::ios_base::sync_with_stdio( false );

    for(int T = 0; T < 3; ++T){
        int height, width;
        std::cin >> height >> width;

        int gn = 0;
        for(int h=0; h<height; h+=2){
            cache.clear();
            auto board = std::vector<std::vector<char>> (width, std::vector<char> (2, '#'));
            for(int y = 0; y<2; ++y){
                for(int x = 0; x<width; ++x){
                    std::cin >> board[x][y];
                }
                if(height%2 == 1 && h == height-1 && y==0) break;
            }

            gn ^= grundy(board, 0, width);
        }
        if(gn) std::cout << "Y" << std::endl;
        else std::cout << "M" << std::endl;
    }
}