#include <bits/stdc++.h>

typedef unsigned long long ull;
constexpr int pow_ten[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};

ull phi(ull N){
    ull ans = N;
    for(ull i = 2; i*i <= N; ++i){
        if(N%i == 0){
            ans -= ans/i;
            while(N%i==0) N/=i;
        }
    }
    if(N>1) ans -= ans / N;
    return ans;
}

ull mod_pow(ull N, ull M, ull K){
    if(M==0) return 1uLL;
    ull ans = 1;
    while(M){
        if(M&1) ans = (ans * N) % K;
        N = (N * N) % K;
        M >>= 1uLL;
    }
    return ans;
}

ull solve_2(ull b, ull i, ull n){
    if(n==1) return 0uLL;
    if(i==0) return 1uLL;
    else if(i==1) return 2uLL;
    else if(i==2) return 4uLL;
    else if(i==3) return 16%n;
    else if(i==4) return 65536%n;

    ull phi_n = phi(n);

    return mod_pow(b, phi_n + solve_2(b, i-1, phi_n), n);
}


ull solve(ull b, ull i, ull n){
    if(b==1) return 1uLL;

    if(i==0) return 1uLL;
    else if(i==1) return b%n;
    else if(i==2) return mod_pow(b,b,n);

    if(n==1) return 0uLL;
    ull phi_n = phi(n);

    return mod_pow(b, phi_n + solve(b, i-1, phi_n), n);
}

std::string fill_zero(ull ans, ull n){
    std::string filled = std::to_string(ans);
    assert(filled.size() <= n);
    
    std::string padding = std::string(n - filled.size(), '0');
    return (padding + filled);
}


int main(int argc, char* argv[]){
    std::cin.tie( nullptr );std::cout.tie( nullptr );
    std::ios_base::sync_with_stdio( false );

    ull b, i, n;
    std::cin >> b;
    while(b){
        std::cin >> i >> n;

        if(b==2) std::cout << fill_zero(solve_2(b,i,pow_ten[n]), n) << '\n';
        else std::cout << fill_zero(solve(b,i,pow_ten[n]), n) << '\n';

        std::cin >> b;
    }

    return 0;
}