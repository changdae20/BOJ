#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>
#include <chrono>
#include <assert.h>

enum class Piece{
    Knight,
    Bishop,
    Rook,
    King,
    Palace
};

std::string Piece2Str( Piece p ){
    switch( p ){
        case Piece::Knight: return "Knight";
        case Piece::Bishop: return "Bishop";
        case Piece::Rook: return "Rook";
        case Piece::King: return "King";
        case Piece::Palace: return "Palace";
        default: return "Unknown";
    }
}

std::vector<std::vector<int>> bake(int n, Piece p, bool save = true){

    // check runtime
    auto start = std::chrono::system_clock::now();

    std::vector<std::vector<int>> v(n, std::vector<int>(n, 0));

    // fill the array with mex (grundy number)
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            if(i==0 && j==0){
                v[i][j] = 0;
                continue;
            }
            // find mex v[0][0] ~ v[i][j]
            std::vector<int> mex;

            // knight
            if( p == Piece::Knight ){
                if(i-2>=0 && j-1>=0) mex.push_back(v[i-2][j-1]);
                if(i-1>=0 && j-2>=0) mex.push_back(v[i-1][j-2]);
            }

            // rook
            if( p == Piece::Rook ){
                for(int k=0; k<i; ++k) mex.push_back(v[k][j]);
                for(int k=0; k<j; ++k) mex.push_back(v[i][k]);
            }

            // bishop
            if( p == Piece::Bishop ){
                for(int k=0; k<std::min(i,j); ++k) mex.push_back(v[i-k-1][j-k-1]);
            }

            // king
            if( p == Piece::King ){
                if(i-1>=0 && j-1>=0) mex.push_back(v[i-1][j-1]);
                if(i-1>=0) mex.push_back(v[i-1][j]);
                if(j-1>=0) mex.push_back(v[i][j-1]);
            }

            // palace ( rook + king)
            if( p == Piece::Palace ){
                if(i-1>=0 && j-1>=0) mex.push_back(v[i-1][j-1]);
                if(i-1>=0) mex.push_back(v[i-1][j]);
                if(j-1>=0) mex.push_back(v[i][j-1]);
                for(int k=0; k<i; ++k) mex.push_back(v[k][j]);
                for(int k=0; k<j; ++k) mex.push_back(v[i][k]);
            }

            // sort and unique
            std::sort(mex.begin(), mex.end());
            mex.erase(std::unique(mex.begin(), mex.end()), mex.end());
            v[i][j] = std::distance(mex.begin(), std::find_if(mex.begin(), mex.end(), [t=0](auto &el) mutable {return el != t++;}));
        }
    }

    // save to file as mex_{piece}.txt
    if(save){
        std::ofstream ofs("mex_" + Piece2Str(p) + ".txt");
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                ofs << std::setw(5) << v[i][j] << " ";
            }
            ofs << std::endl;
        }
        std::cout << "Saved as " << "mex_" << Piece2Str(p) << ".txt" << std::endl;
    }

    // check runtime
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;

    std::cout << "Elapsed time: " << elapsed_seconds.count() << "s" << std::endl;

    return v;
}

unsigned long long grundy(unsigned long long row, unsigned long long col, Piece p){
    switch( p ){
        case Piece::Knight:
            if (row == col) return (row%3 == 2);
            else{
                unsigned long long temp = std::max<>(row,col) - (std::min<>(row,col)/3) * 3;
                unsigned long long temp2 = std::min<>(row,col)%3;
                if(temp>=4) return temp2;
                else if (temp==2 || temp==3) return temp2>0;
                else if (temp==1) return temp2>1;
                else return 0;
            }
        case Piece::Bishop:
            return std::min<>(row, col);
        case Piece::Rook:
            return row^col;
        case Piece::King:
            if((row&1) == (col&1)) return 2*(row&1);
            else return 2*(std::min<>(row,col)&1) + 1;
        case Piece::Palace:
            return 3*((row/3) ^ (col/3)) + (row+col)%3;
        default: return 0;
    }
}

void check(int n, Piece p){
    auto v = bake(n, p, false);
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            assert(v[i][j] == grundy(i, j, p));
        }
    }
}

int main(){
    #ifndef BOJ
    freopen("input.txt", "r", stdin);
    #endif

    unsigned long long N;
    std::cin >> N;
    unsigned long long row,col;
    char p;
    unsigned long long ans = 0;
    while(N--){
        std::cin >> row >> col >> p;
        switch(p){
            case 'N': ans ^= grundy(row, col, Piece::Knight); break;
            case 'B': ans ^= grundy(row, col, Piece::Bishop); break;
            case 'R': ans ^= grundy(row, col, Piece::Rook); break;
            case 'K': ans ^= grundy(row, col, Piece::King); break;
            case 'P': ans ^= grundy(row, col, Piece::Palace); break;
        }
    }
    if(ans){
        std::cout << "koosaga" << std::endl;
    }else{
        std::cout << "cubelover" << std::endl;
    }

    return 0;
}