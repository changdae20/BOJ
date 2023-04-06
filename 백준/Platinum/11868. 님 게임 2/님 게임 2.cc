#include <iostream>
#include <vector>
#include <algorithm>
#include <regex>
#include <string>
#include <numeric>

int main(){
    int n;
    int ans=0;
    int m;
    std::cin >> n;
    while(n--){
        std::cin >> m;
        ans^=m;
    }
    if(!ans) std::cout << "cubelover";
    else std::cout << "koosaga";
    return 0;
}