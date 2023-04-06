#include <bits/stdc++.h>

std::vector<int> smallest_divisor(2000001, 0); // x를 나누는 제일 작은 소인수를 저장 (소인수 분해를 logN에 처리)
std::vector<std::vector<int>> prime_factorized(2000001, std::vector<int>());

void build_smallest_divisor(){
    for(int i = 2; i <= 2000000; i++){
        if(smallest_divisor[i] == 0){
            smallest_divisor[i] = i;
            for(int j = i * 2; j <= 2000000; j += i){
                if(smallest_divisor[j] == 0){
                    smallest_divisor[j] = i;
                }
            }
        }
    }
    return;
}

void prime_factorization( std::vector<int>& v, int N){
    while(N != 1){
        v.push_back(smallest_divisor[N]);
        N /= smallest_divisor[N];
    }
    return;
}

int main( int argc, char *argv[] ) {
    std::cin.tie( 0 );
    std::ios::sync_with_stdio( false );
    std::cout.tie( 0 );
#ifndef BOJ
    freopen( argv[ 1 ], "r", stdin );
#endif
    int MAX, Q;
    std::cin >> MAX >> Q;

    build_smallest_divisor();
    unsigned long long A, B;
    while ( Q-- ) {
        std::cin >> A >> B;
        
        if(prime_factorized[A].size()==0) prime_factorization(prime_factorized[A], A);
        if(prime_factorized[B].size()==0) prime_factorization(prime_factorized[B], B);

        std::vector<int> v(prime_factorized[A].size() + prime_factorized[B].size());
        std::merge(prime_factorized[A].begin(), prime_factorized[A].end(), prime_factorized[B].begin(), prime_factorized[B].end(), v.begin());

        long long ans = 1;
        for(auto it = v.begin(); it!=v.end();){
            if(std::distance(it, v.end()) < 2 ){
                break;
            }
            if(*it == *(std::next(it,1))){
                ans *= (*it);
                it = std::next(it, 2);
            }else{
                ++it;
            }
        }
        std::cout << ans << " ";
    }
    std::cout << '\n';

    return 0;
}