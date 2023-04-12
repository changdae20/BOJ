#include <bits/stdc++.h>

constexpr bool isPrime(size_t n) noexcept {
    if (n <= 1) return false;
    for (size_t i = 2; i*i <= n; i++){
        if (n % i == 0) return false;
    }
    return true;
}

template <std::size_t N>
constexpr std::array<std::size_t, N> get_primes() noexcept{
    constexpr auto primes = []{
        std::array<std::size_t, N> primes{2,3};
        
        size_t i = 2;
        for(size_t p = primes[i-1] + 2;; p += 2){
            if(isPrime(p)){
                primes[i++] = p;
                if(i>=N) break;
            }
        }
        return primes;
    }();

    return primes;
}

int main(){
    constexpr auto primes = get_primes<5000>();
	int M,N;
	std::cin >> M >> N;
	auto it = std::lower_bound(primes.begin(), primes.end(), M);
	auto it2 = std::lower_bound(primes.begin(), primes.end(), N+1);
	if(it==it2){
		std::cout << -1 << std::endl;
	}else{
		std::cout << std::accumulate(it,it2,0) << '\n' << *it << std::endl;
	}
	
	return 0;
}