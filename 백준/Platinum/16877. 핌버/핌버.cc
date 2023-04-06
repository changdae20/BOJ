#include <bits/stdc++.h>

std::vector<uint> cache(3000001);

std::array<uint, 31> fibos = { 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269, 2178309 };

void bake(){
    cache[0] = 0;
    cache[1] = 1;
    cache[2] = 2;
    cache[3] = 3;
    for(int i=4; i<=3000000; ++i){
        std::array<bool, 31> s = {false, };
        for(const auto& fibo : fibos){
            if(fibo>i) break;
            s[cache[i-fibo]] = true;
        }
        uint mex = 0;
        while ( s[mex] )
            ++mex;
        cache[i] = mex;
    }
    return;
}

int main() {
    #ifndef BOJ
    freopen("input.txt","r",stdin);
    #endif
    std::cin.tie( nullptr );
    std::cout.tie( nullptr );
    std::ios_base::sync_with_stdio( false );
    bake();
    size_t N;
    uint K;
    uint ans = 0;
    std::cin >> N;
    std::array<uint, 100000> arr;
    for(size_t i=0; i<N; ++i) std::cin >> arr[i];
    for(size_t i=0; i<N; ++i) ans ^= cache[arr[i]];
    if ( ans )
        std::cout << "koosaga\n";
    else
        std::cout << "cubelover\n";

    return 0;
}