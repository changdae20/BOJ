#include <bits/stdc++.h>

std::vector<int> data(1000001);

int calc_prime(int N){
    for(int i=2;i*i<=N;++i){
        if(N%i==0) return -1;
    }
    return 1;
}

int is_prime(int N){
    if(data[N]==0){
        data[N] = calc_prime(N);
    }
    return data[N];
}
int main(){
    #ifndef BOJ
    freopen("input.txt", "r",stdin);
    #endif

    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    int N;
    std::cin >> N;

    while(N){
        for(int a = 3; a<=N/2; a+=2){
            if(is_prime(a)==1 and is_prime(N-a)==1){
                std::cout << N << " = " << a << " + " << N-a << '\n';
                break;
            }
        }
        std::cin >> N;
    }

    return 0;
}