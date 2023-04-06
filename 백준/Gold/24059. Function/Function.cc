#include <iostream>
#include <vector>
#include <algorithm>
#include <regex>
#include <string>
#include <numeric>

unsigned long long pow_mod(unsigned long long a, unsigned long long b, unsigned long long m){
    unsigned long long res = 1;
    while(b){
        if(b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

int main(){
    unsigned long long n;
    std::cin >> n;
    std::vector<unsigned long long> v(n+1);
    for(unsigned long long i = 0; i <=n; i++){
        std::cin >> v[i];
    }
    unsigned long long m;
    std::cin >> m;

    if(n == 0){
        std::cout << v[0] % m << std::endl;
    }else if( n == 1){
        std::cout << pow_mod(v[1], v[0], m) << std::endl;
    }else if( n == 2){
        std::cout << pow_mod(v[2], pow_mod(v[1], v[0], m-1) + m - 1, m) << std::endl;
    }

    return 0;
}