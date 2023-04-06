#include <bits/stdc++.h>

std::array<std::array<int, 9>, 9> board;
std::vector<std::pair<int,int>> blanks;

std::vector<int> make_candidates(int x, int y){
    std::vector<int> candidates;
    for(int i=1; i<=9; ++i){
        bool is_valid = true;
        // check row
        for(int j=0; j<9; ++j){
            if(board[x][j] == i) is_valid = false;
        }

        // check column
        for(int j=0; j<9; ++j){
            if(board[j][y] == i) is_valid = false;
        }

        // check 3x3
        int x_start = x/3*3;
        int y_start = y/3*3;
        for(int j=0; j<3; ++j){
            for(int k=0; k<3; ++k){
                if(board[x_start+j][y_start+k] == i) is_valid = false;
            }
        }

        if(is_valid) candidates.push_back(i);
    }

    return candidates;
}

bool solve(int idx){
    auto &[x,y] = blanks[idx];
    auto candidates = make_candidates(x, y);

    if(candidates.size() == 0) return false;
    else{
        if(idx == blanks.size()-1){
            board[x][y] = candidates[0];
            return true;
        }
        else{
            for(auto c : candidates){
                board[x][y] = c;
                if(solve(idx+1)) return true;
            }
            board[x][y] = 0;
            return false;
        }
    }
}
int main(int argc, char *argv[]){
    #ifndef BOJ
    freopen(argv[1], "r", stdin);
    #endif

    char c;
    for(int j=0; j<9; ++j){
        for(int i=0; i<9; ++i){
            std::cin >> c;
            board[i][j] = static_cast<int>(c - '0');
            if(board[i][j] == 0) blanks.push_back(std::make_pair(i,j));
        }
    }

    if(blanks.size()){
        solve(0);
    }

    for(int j=0; j<9; ++j){
        for(int i=0; i<9; ++i){
            std::cout << board[i][j];
        }
        std::cout << '\n';
    }

    return 0;
}