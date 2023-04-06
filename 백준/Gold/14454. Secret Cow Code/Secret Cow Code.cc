#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>
#include <iterator>

unsigned long long calc(unsigned long long n, unsigned long long k, unsigned long long ans) {
    if(n == ans) return k;

    if(k>=(n>>1)){ // 
        return calc(n>>1, ((k-1) + (n>>1))%(n>>1), ans);
    }else{
        return calc(n>>1, k, ans);
    }
}
int main(){
    #ifndef BOJ
    freopen("input.txt", "r", stdin);
    #endif

    std::string word;
    unsigned long long n;

    std::cin >> word >> n;

    n--;

    unsigned long long init = static_cast<unsigned long long> (word.size());

    while(init < n){
        init <<=1;
    }

    std::cout << word[calc(init, n, word.size())] << std::endl;
}