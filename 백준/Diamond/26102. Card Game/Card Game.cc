#include <bits/stdc++.h>


std::vector<std::vector<char>> odd_board;
std::vector<std::vector<char>> even_board;

std::vector<int> odd_cache(26 * 26*26*26 + 26 * 26*26 + 26 * 26 + 26 + 1, -1);
std::vector<int> even_cache(26 * 26 * 26 * 26 + 26 * 26 * 26 + 26 * 26 + 26 + 1, -1);

int h, w;

inline int n_ary(int x, int y, int a, int b) {
    return x * 26*26*26 + y * 26*26 + a * 26 + b;
}

enum class MODE {
    EVEN,
    ODD
};

int grundy(int x, int y, int a, int b, MODE mode) { // range half - exclusive. [x,x+a) x [y,y+b)
    if (x < 0) return 0;
    if (y < 0) return 0;
    if (x + a > 26) return 0;
    if (y + b > 26) return 0;
    if (a < 1 || b < 1) return 0;

    std::vector<std::vector<char>>* board_pointer;
    std::vector<int>* cache_pointer;

    switch (mode) {
    case MODE::EVEN:
        board_pointer = &even_board;
        cache_pointer = &even_cache;
        if (even_cache[n_ary(x, y, a, b)] != -1) return even_cache[n_ary(x, y, a, b)];
        break;
    case MODE::ODD:
        board_pointer = &odd_board;
        cache_pointer = &odd_cache;
        if (odd_cache[n_ary(x, y, a, b)] != -1) return odd_cache[n_ary(x, y, a, b)];
        break;
    default:
        board_pointer = &odd_board;
        cache_pointer = &odd_cache;
        break;
    }

    std::vector<bool> mex(4000, false);

    for (int m = x; m < x + a; ++m) {
        for (int n = y; n < y + b; ++n) {
            if ((*board_pointer)[m][n] == '.') continue; // (m,n)은 못놓는 위치

            int gn = 0;
            
            switch ((*board_pointer)[m][n]) {
            case '.':
                continue;
            case 'R':
                gn ^= grundy(x, y, a, n - y, mode);
                gn ^= grundy(x, n + 1, a, y + b - n - 1, mode);
                break;
            case 'B':
                gn ^= grundy(x, y, m - x, b, mode);
                gn ^= grundy(m + 1, y, x + a - m - 1, b, mode);
                break;
            case 'G':
                gn ^= grundy(x, y, m - x, n - y, mode);
                gn ^= grundy(m + 1, y, x + a - m - 1, n - y, mode);
                gn ^= grundy(x, n + 1, m - x, y + b - n - 1, mode);
                gn ^= grundy(m + 1, n + 1, x + a - m - 1, y + b - n - 1, mode);
                break;
            }
            mex[gn] = true;
        }
    }

    int gn = std::distance(mex.begin(), std::find(mex.begin(), mex.end(), false));

    (*cache_pointer)[n_ary(x, y, a, b)] = gn;
    return gn;
}
int main() {
    #ifndef BOJ
    freopen("input.txt","r",stdin);
    #endif
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    std::cin >> h >> w;

    odd_board = std::vector<std::vector<char>>(26, std::vector<char>(26, '.'));
    even_board = std::vector<std::vector<char>>(26, std::vector<char>(26, '.'));
    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            MODE mode;
            if ((x + y) & 1) mode = MODE::ODD;
            else mode = MODE::EVEN;

            switch (mode) {
            case MODE::EVEN:
                std::cin >> even_board[12 + (x - y) / 2][(x + y) / 2];
                break;
            case MODE::ODD:
                std::cin >> odd_board[12 + (x - y - 1) / 2][(x + y) / 2];
                break;
            }
        }
    }
    if (grundy(0, 0, 26, 26, MODE::EVEN) ^ grundy(0, 0, 26, 26, MODE::ODD)) std::cout << "W\n";
    else std::cout << "L\n";

    return 0;
}