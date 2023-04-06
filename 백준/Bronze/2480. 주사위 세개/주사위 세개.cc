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

    int a,b,c;
    std::cin >> a >> b >> c;

    if(a==b && b==c){
        std::cout << 10000 + a*1000;
    }else if(a==b || b==c || a==c){
        if(a==b){
            std::cout << 1000 + a*100;
        }else if(b==c){
            std::cout << 1000 + b*100;
        }else{
            std::cout << 1000 + c*100;
        }
    }else{
        std::cout << std::max<>({a,b,c}) * 100;
    }
    return 0;
}