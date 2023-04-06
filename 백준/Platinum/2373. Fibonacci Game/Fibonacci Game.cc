#include <bits/stdc++.h>

std::vector<unsigned long long> fibo;

void bake_fibo(){
    fibo.push_back(1);
    fibo.push_back(2);

    unsigned long long next = fibo[fibo.size()-1l] + fibo[fibo.size()-2l];
    while(next <= 1'000'000'000'000'000uLL){
        fibo.push_back(next);
        next = fibo[fibo.size()-1l] + fibo[fibo.size()-2l];
    }
    return;
}
int main(int argc, char* argv[]) {
    bake_fibo();
    unsigned long long N;
    std::cin >> N;
    
    auto it = std::lower_bound(fibo.begin(), fibo.end(), N);
    if(*it == N){
        std::cout << -1 << std::endl;
    }else{
        while(true){
            auto it = std::lower_bound(fibo.begin(), fibo.end(), N);
            if(*it == N){
                std::cout << N << std::endl;
                break;
            }else{
                N -= *std::prev(it);
            }
        }
    }
    
    return 0;
}