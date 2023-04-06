#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio( false );std::cin.tie( NULL );std::cout.tie( NULL );

enum class Color{
    WHITE = 119,
    YELLOW = 121,
    RED = 114,
    ORANGE = 111,
    GREEN = 103,
    BLUE = 98
};

// permutation의 Base Case
template <typename T>
T permute_helper(T* arg) {
    return *arg;
}

// variadic template으로 구현한 permution. 포인터들을 입력으로 받으며 각 자리에 다음 인자 주소에 있던 값을 넣는다.
template <typename T, typename... Types>
T permute_helper(T* arg, Types... args) {
    T tmp = *arg;
    *arg = permute_helper(args...);
    return tmp;
}

// 돌리는 면의 경우 permute가 2번씩 일어나야 1번의 회전임. (돌아가는 색깔이 총 8개)
template <typename T, typename... Types>
void permute2(T* arg, Types... args) {
    for(int i=0; i<2; ++i) permute_helper(arg, args..., arg);
    return;
}

// 돌리는 면의 테두리의 경우 permute가 3번씩 일어나야 1번의 회전임. (돌아가는 색깔이 총 12개)
template <typename T, typename... Types>
void permute3(T* arg, Types... args) {
    for(int i=0; i<3; ++i) permute_helper(arg, args..., arg);
    return;
}

class Cube{
public:
Cube(){
    for(int i=0;i<9;++i){
        up[i] = Color::WHITE;
        down[i] = Color::YELLOW;
        front[i] = Color::RED;
        back[i] = Color::ORANGE;
        left[i] = Color::GREEN;
        right[i] = Color::BLUE;
    }
};

// 각 회전마다 돌아가는 색깔들의 위치만 고려해서 permute시켜준다.
// 이때 -는 +를 세번 한 것과 같다.
void operator() (){
    char a,b;
    std::cin >> a >> b;
    switch(a){
        case 'U':
            permute3(front,front+1,front+2,right,right+1,right+2,back,back+1,back+2,left,left+1,left+2);
            permute2(up,up+3,up+6,up+7,up+8,up+5,up+2,up+1);
            if(b=='-'){
                permute3(front,front+1,front+2,right,right+1,right+2,back,back+1,back+2,left,left+1,left+2);
                permute2(up,up+3,up+6,up+7,up+8,up+5,up+2,up+1);
                permute3(front,front+1,front+2,right,right+1,right+2,back,back+1,back+2,left,left+1,left+2);
                permute2(up,up+3,up+6,up+7,up+8,up+5,up+2,up+1);
            }
            break;
        case 'D':
            permute3(front+8,front+7,front+6,left+8,left+7,left+6,back+8,back+7,back+6,right+8,right+7,right+6);
            permute2(down,down+3,down+6,down+7,down+8,down+5,down+2,down+1);
            if(b=='-'){
                permute3(front+8,front+7,front+6,left+8,left+7,left+6,back+8,back+7,back+6,right+8,right+7,right+6);
                permute2(down,down+3,down+6,down+7,down+8,down+5,down+2,down+1);
                permute3(front+8,front+7,front+6,left+8,left+7,left+6,back+8,back+7,back+6,right+8,right+7,right+6);
                permute2(down,down+3,down+6,down+7,down+8,down+5,down+2,down+1);
            }
            break;
        case 'L':
            permute3(front,up+6,up+3,up,back+2,back+5,back+8,down+6,down+3,down,front+6,front+3);
            permute2(left,left+3,left+6,left+7,left+8,left+5,left+2,left+1);
            if(b=='-'){
                permute3(front,up+6,up+3,up,back+2,back+5,back+8,down+6,down+3,down,front+6,front+3);
                permute2(left,left+3,left+6,left+7,left+8,left+5,left+2,left+1);
                permute3(front,up+6,up+3,up,back+2,back+5,back+8,down+6,down+3,down,front+6,front+3);
                permute2(left,left+3,left+6,left+7,left+8,left+5,left+2,left+1);
            }
            break;
        case 'R':
            permute3(front+2,front+5,front+8,down+2,down+5,down+8,back+6,back+3,back,up+2,up+5,up+8);
            permute2(right,right+3,right+6,right+7,right+8,right+5,right+2,right+1);
            if(b=='-'){
                permute3(front+2,front+5,front+8,down+2,down+5,down+8,back+6,back+3,back,up+2,up+5,up+8);
                permute2(right,right+3,right+6,right+7,right+8,right+5,right+2,right+1);
                permute3(front+2,front+5,front+8,down+2,down+5,down+8,back+6,back+3,back,up+2,up+5,up+8);
                permute2(right,right+3,right+6,right+7,right+8,right+5,right+2,right+1);
            }
            break;
        case 'F':
            permute3(up+8,up+7,up+6,left+2,left+5,left+8,down,down+1,down+2,right+6,right+3,right);
            permute2(front,front+3,front+6,front+7,front+8,front+5,front+2,front+1);
            if(b=='-'){
                permute3(up+8,up+7,up+6,left+2,left+5,left+8,down,down+1,down+2,right+6,right+3,right);
                permute2(front,front+3,front+6,front+7,front+8,front+5,front+2,front+1);
                permute3(up+8,up+7,up+6,left+2,left+5,left+8,down,down+1,down+2,right+6,right+3,right);
                permute2(front,front+3,front+6,front+7,front+8,front+5,front+2,front+1);
            }
            break;
        case 'B':
            permute3(up,up+1,up+2,right+2,right+5,right+8,down+8,down+7,down+6,left+6,left+3,left);
            permute2(back,back+3,back+6,back+7,back+8,back+5,back+2,back+1);
            if(b=='-'){
                permute3(up,up+1,up+2,right+2,right+5,right+8,down+8,down+7,down+6,left+6,left+3,left);
                permute2(back,back+3,back+6,back+7,back+8,back+5,back+2,back+1);
                permute3(up,up+1,up+2,right+2,right+5,right+8,down+8,down+7,down+6,left+6,left+3,left);
                permute2(back,back+3,back+6,back+7,back+8,back+5,back+2,back+1);
            }
            break;
    }
    return;
}

friend std::ostream& operator<< (std::ostream& os, const Cube& c);
private:
Color up[9];
Color down[9];
Color front[9];
Color back[9];
Color left[9];
Color right[9];
};

std::ostream& operator<< (std::ostream& os, const Cube& c){
    for(int i=0;i<9;++i){
        os << static_cast<char>(c.up[i]) << ((i%3==2) ? "\n" : "");
    }
    return os;
}

int main( int argc, char *argv[] ) {
#ifndef BOJ
    freopen( argv[ 1 ], "r", stdin );
#endif
    fastio;

    int T;
    std::cin >> T;
    while(T--){
        int N;
        Cube c;
        std::cin >> N;
        while(N--) c();
        std::cout << c;
    }

    return 0;
}