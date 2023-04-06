#include <iostream>
#include <vector>
#include <type_traits>
#include <algorithm>
#include <numeric>
#include <cmath>

std::vector<int> bin(uint64_t num){
    std::vector<int> v;

    do{
        v.push_back(num%2);
    }while(num/=2);

    return v;
}

uint64_t new_pow(uint64_t a, const int& b){
    auto v = bin(b);
    uint64_t ans = 1;
    std::for_each(v.begin(), v.end(), [&ans, &a](auto& el){
        if(el) ans*=a;
        a*=a;
    });
    return ans;
}

int main(){
    uint64_t num;
    std::cin >> num;
    auto v = bin(num);
    std::cout << std::accumulate(v.begin(), v.end(), 0LL, [&v](const auto &a, const auto &b){ return a + ( b * new_pow(3, &b - &v[0]) ); });
}