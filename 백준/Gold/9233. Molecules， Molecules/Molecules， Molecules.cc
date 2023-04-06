#include <bits/stdc++.h>

enum class Atom{
    H = 'H',
    O = 'O',
    N = 'N',
    C = 'C'
};

bool is_valid( std::vector<std::vector<int>> &grid, int current_x, int current_y ){
    // std::cout << "Line " << __LINE__ << std::endl;
    // std::cout << "Enter is_valid with current_x : " << current_x << ", current_y : " << current_y << ", grid[x][y] : " << grid[current_x][current_y] << std::endl;
    if(current_x == 5 && current_y == 5 && grid[current_x][current_y] == 0){ // terminal condition
        return true;
    }
    if(grid[current_x][current_y] > 2){ // 연결 할 수 있는 방법이 아래/오른쪽 밖에 없는데 연결해야 할 곳이 2개 이상 남아있으면 불가능한 경우.
        return false;
    }else if(grid[current_x][current_y] == 2){ // 2인 경우 오른쪽 아래 다 연결해야함
        if( grid[current_x+1][current_y] == 0 || grid[current_x][current_y+1] == 0){ // 근데 오른쪽이나 아래가 연결 불가능하면? -> 불가능
            return false;
        }else{
            --grid[current_x+1][current_y];
            --grid[current_x][current_y+1];
            if( is_valid(grid, 1 + (current_x % 5), current_y + (current_x==5 ? 1 : 0))){
                return true;
            }else{
                grid[current_x+1][current_y]+=1;
                grid[current_x][current_y+1]+=1;
                return false;
            }
        }
    }else if(grid[current_x][current_y] == 1){
        if( grid[current_x+1][current_y] ){
            --grid[current_x+1][current_y];
            if( is_valid(grid, 1 + (current_x % 5), current_y + (current_x==5 ? 1 : 0))){
                return true;
            }else{
                ++grid[current_x+1][current_y];
            }
        }
        if( grid[current_x][current_y+1] ){
            --grid[current_x][current_y+1];
            if( is_valid(grid, 1 + (current_x % 5), current_y + (current_x==5 ? 1 : 0))){
                return true;
            }else{
                ++grid[current_x][current_y+1];
            }
        }
        return false;
    }else{
        return is_valid(grid, 1 + (current_x % 5), current_y + (current_x==5 ? 1 : 0));
    }
}
bool solve( int rows, int cols ){
    std::vector<std::vector<int>> grid(7, std::vector<int>(7, 0));
    char input;
    for( int y = 1; y <= rows; ++y ){
        for( int x = 1; x <= cols; ++x ){
            std::cin >> input;
            switch (input){
            case 'H':
                grid[x][y] = 1;
                break;
            case 'O':
                grid[x][y] = 2;
                break;
            case 'N':
                grid[x][y] = 3;
                break;
            case 'C':
                grid[x][y] = 4;
                break;
            default:
                break;
            }
        }
    }

    return is_valid(grid, 1, 1);
}

int main( int argc, char *argv[] ) {
    std::cin.tie( 0 );
    std::ios::sync_with_stdio( false );
    std::cout.tie( 0 );
#ifndef BOJ
freopen( argv[ 1 ], "r", stdin );
#endif

    int rows, cols;
    int molecule_idx = 0;
    std::cin >> rows >> cols;

    while(rows!=0 && cols!=0){
        if(solve(rows, cols)){
            std::cout << "Molecule " << ++molecule_idx << " is valid.\n";
        }else {
            std::cout << "Molecule " << ++molecule_idx << " is invalid.\n";
        }
        std::cin >> rows >> cols;
    }
    

    return 0;
}

// 무조건 7*7로 그리드를 채운다음에
