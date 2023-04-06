#include <bits/stdc++.h>

std::vector<std::vector<bool>> board;

std::vector<int> cache(20 * 8000 + 20 * 400 + 20*20 + 20 + 1, -1);

int h, w;

inline int n_ary(int x, int y, int a, int b) {
    return x* 8000 + y*400 + a*20 + b;
}

int grundy(int x, int y, int a, int b){ // range half - exclusive. [x,x+a) x [y,y+b)
    if( x < 0 ) return 0;
    if( y < 0 ) return 0;
    if( x+a > w ) return 0;
    if( y+b > h ) return 0;
    if( a < 1 || b < 1 ) return 0;
    if(cache[n_ary(x,y,a,b)] != -1) return cache[n_ary(x,y,a,b)];

    int ans = 0;

    std::vector<bool> mex(400, false);

    for(int m = x; m < x+a; ++m){
        for(int n = y; n < y+b; ++n){
            if( !board[m][n] ) continue; // (m,n)은 못놓는 위치

            int gn = 0;

            gn ^= grundy(x, y, m-x, n-y);
            gn ^= grundy(m+1, y, x+a-m-1, n-y);
            gn ^= grundy(x, n+1, m-x, y+b-n-1);
            gn ^= grundy(m+1, n+1, x+a-m-1, y+b-n-1);

            mex[gn] = true;

        }
    }

    int gn = std::distance(mex.begin(), std::find(mex.begin(), mex.end(), false));

    cache[n_ary(x,y,a,b)] = gn;
    return gn;
}
int main() {
    std::cin.tie( nullptr );
    std::cout.tie( nullptr );
    std::ios_base::sync_with_stdio( false );
    
    std::cin >> h >> w;

    board = std::vector<std::vector<bool>> (w, std::vector<bool>(h, true));

    char c;
    
    for(int y=0; y<h; ++y){
        for(int x=0; x<w;++x){
            std::cin >> c;
            board[x][y] = (c!='X');
        }
    }

    if(grundy(0,0,w,h)) std::cout << "First\n";
    else std::cout << "Second\n";

    return 0;
}