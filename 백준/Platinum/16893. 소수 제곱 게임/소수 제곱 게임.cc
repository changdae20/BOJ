#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

std::map<unsigned int, unsigned int> cache;

unsigned int grundy(unsigned int N){
    if(N==0u) return cache[N] = 0u;
    
    int count_one = __builtin_popcount(N);
    if(count_one==1) return cache[N] = static_cast<unsigned int> (__builtin_ctz(N)+1);
    else if(cache.find(N) != cache.end()) return cache[N];

    unsigned int s = 0u;

    for(int i=1; i<=32-__builtin_clz(N); ++i){
        unsigned int right = N&((1u<<(i-1))-1u);
        unsigned int left = (N^right) >> i;

        s |= (1<<grundy(right|left));
    }

    unsigned int ans = 0u;
    while(s & (1<<ans)) ++ans;

    cache[N] = ans;
    return ans;
}

std::map<int, unsigned int> m;

void prime_factorization(int N){
    for(int x=2; x*x <= N; ++x){
        if(N%x==0){
            int exp = -1;
            while(N%x==0){
                N /= x;
                ++exp;
            }
            m[x] |= (1 << exp);
        }
    }
    if(N>1) m[N] |= 1;
    return;
}

int main(int argc, char* argv[]) {
    #ifndef BOJ
    freopen(argv[1], "r", stdin);
    #endif
    fastio;
	
	int N,x;
    std::cin >> N;
    while(N--){
        std::cin >> x;
        prime_factorization(x);
    }

    unsigned int gn = 0u;
    
    for(auto [prime,bit] : m){
        gn ^= grundy(bit);
    }

    if(gn) std::cout << "koosaga\n";
    else std::cout << "cubelover\n";

    return 0;
}