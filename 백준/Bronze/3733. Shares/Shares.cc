#include <iostream>
#include <vector>
#include <string>

int main(){
    #ifndef BOJ
    freopen("input.txt", "r", stdin);
    #endif

    int N,S;
    while(std::cin >> N >> S){
        std::cout << S/(N+1) << std::endl;
    }
}