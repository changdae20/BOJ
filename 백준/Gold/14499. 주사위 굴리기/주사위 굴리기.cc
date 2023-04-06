#include <bits/stdc++.h>

enum class Where{
    Left,
    Right,
    Up,
    Down
};

int N,M,x,y,K;

class Dice{
public:
    int top, front, right, left, back, bottom, x,y;
    Dice() : top(0), front(0), right(0), left(0), back(0), bottom(0), x(0), y(0) {}
    Dice(int x, int y) : top(0), front(0), right(0), left(0), back(0), bottom(0), x(x), y(y) {}
    bool roll(Where w){
        int tmp;
        if(w == Where::Up){
            if(y == 0) return false;
            tmp = top;
            top = front;
            front = bottom;
            bottom = back;
            back = tmp;
            --y;
        }else if(w == Where::Down){
            if(y == N-1) return false;
            tmp = top;
            top = back;
            back = bottom;
            bottom = front;
            front = tmp;
            ++y;
        }else if(w == Where::Right){
            if(x == M-1) return false;
            tmp = top;
            top = left;
            left = bottom;
            bottom = right;
            right = tmp;
            ++x;
        }else if(w == Where::Left){
            if(x == 0) return false;
            tmp = top;
            top = right;
            right = bottom;
            bottom = left;
            left = tmp;
            --x;
        }
        return true;
    }
};

int main( int argc, char *argv[] ) {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    std::cout.tie(0);
#ifndef BOJ
freopen( argv[ 1 ], "r", stdin );
#endif
    
    std::cin >> N >> M >> x >> y >> K;

    std::vector<std::vector<int>> map(N, std::vector<int>(M, 0));
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            std::cin >> map[i][j];
        }
    }

    std::vector<Where> query;

    while(K--){
        int q;
        std::cin >> q;
        if(q == 1){
            query.push_back(Where::Right);
        }else if(q == 2){
            query.push_back(Where::Left);
        }else if(q == 3){
            query.push_back(Where::Up);
        }else if(q == 4){
            query.push_back(Where::Down);
        }
    }

    Dice dice(y,x);

    for(auto &q : query){
        if(dice.roll(q)){
            if(map[dice.y][dice.x] == 0){
                map[dice.y][dice.x] = dice.bottom;
            }else{
                dice.bottom = map[dice.y][dice.x];
                map[dice.y][dice.x] = 0;
            }
            std::cout << dice.top << std::endl;
        }
    }

    return 0;
}