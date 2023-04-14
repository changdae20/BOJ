#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

template <size_t N>
constexpr std::array<size_t, N+1> get_fibonacci(){
    constexpr auto helper = [](){
        std::array<size_t, N+1> arr = {1,1,};
        for(int i=2; i<=N; ++i){
            arr[i]=(arr[i-1]+arr[i-2])%10007;
        }
        return arr;
    };

    return helper();
}

int main(int argc, char* argv[]) {
    #ifndef BOJ
    freopen(argv[1], "r", stdin);
    #endif
    fastio;
	
	constexpr auto fibonacci = get_fibonacci<1000>();

    int x;
    std::cin >> x;
    std::cout << fibonacci[x] << std::endl;
    
    return 0;
}