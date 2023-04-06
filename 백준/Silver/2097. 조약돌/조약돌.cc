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
#include <map>

int main(){
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios_base::sync_with_stdio(false);

    #ifndef BOJ
    freopen("input.txt", "r", stdin);
    #endif

    int N;
    std::cin >> N;

    if(N<=4){
        std::cout << 4 << '\n';
        return 0;
    }
    int i = 1;
    for(;;++i) if (i*i>=N) break;
    std::cout << (2*((i-1)+((N%i==0) ? (N/i - 1) : (N/i)))) << '\n';

    return 0;
}