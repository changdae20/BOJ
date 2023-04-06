#include <bits/stdc++.h>

int main(int argc, char* argv[]){
#ifndef BOJ
    freopen(argv[1], "r", stdin);
#endif
    std::cin.tie(NULL);
    std::ios::sync_with_stdio( false );
    std::cout.tie(NULL);
    
    unsigned long long n;
    std::cin >> n;

    unsigned long long l = 0;
    unsigned long long r = 4294967296LL; // 2^32

    if(n==0uLL){ // 0은 이분탐색에서 찾을 수 없으므로 예외처리
        std::cout << "0\n";
    }else{
        while(l+1<r){
            unsigned long long mid = (l+r)/2uLL;

            if(mid*mid >= n) r = mid;
            else l = mid;
        }

        std::cout << r << '\n';
    }
    return 0;
}