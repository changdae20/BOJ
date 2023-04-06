#include <bits/stdc++.h>

int main(int argc, char** argv){
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios_base::sync_with_stdio(false);

    #ifndef BOJ
    freopen(argv[1], "r", stdin);
    #endif

    int N,M;
    std::cin >> N >> M;

    std::vector<std::vector<char>> board(N, std::vector<char>(M, ' '));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            std::cin >> board[i][j];
        }
    }

    int ans = 50*50;

    for(int i=0; i<=N-8; i++){
        for(int j=0; j<=M-8; j++){
            int count = 0;
            for(int x=0; x<8; x++){
                for(int y=0; y<8;y++){
                    if(board[i+x][j+y] != ((x+y)%2 == 0 ? 'W' : 'B')){
                        count++;
                    }
                }
            }
            ans = std::min<>(ans, count);
            ans = std::min<>(ans, 64-count);
        }
    }

    std::cout << ans << std::endl;

    return 0;
}