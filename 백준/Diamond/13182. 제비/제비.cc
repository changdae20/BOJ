#include <iostream>
#include <numeric>
#include <functional>
#include <utility>
#include <vector>

const int MOD = 1000000007;

long long new_pow(long long base, long long exponent){
    long long ans = 1;
    while(exponent){
        if(exponent & 1){
            ans = (ans * base) % MOD;
        }
        exponent >>= 1;
        base = (base * base) % MOD;
    }
    return ans;
}

int main(){
    int T;
    std::cin >> T;
    while(T--){
        int R,G,B,K;
        std::cin >> R >> G >> B >> K;
        long long first = K;

        long long second = new_pow(B,K) * new_pow(new_pow(B+1,K),MOD-2) % MOD;
        second = (1 - second + MOD) % MOD;
        second = second * R % MOD;

        long long third = G * new_pow(B,MOD-2) % MOD;
        third = third * K % MOD;
        std::cout << (first + second + third) % MOD << std::endl;
    }
    return 0;
}