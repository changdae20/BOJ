#include <iostream>
#include <vector>
#include <string>

int main(){
    #ifndef BOJ
    freopen("input.txt", "r", stdin);
    #endif

    int n;
    std::cin >> n;
    std::cout << (n%4==0 && n%100!=0 || n%400==0 ? 1 : 0) << std::endl;
}