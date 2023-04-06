#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

std::vector<int> cache(10001, -1);

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

int grundy( const std::array<size_t, 1229> &primes, std::vector<int> &v ){
    int cnt = 0;
    for(auto num : v){
        int num_c = num;
        if(cache[num] != -1){
            cnt += cache[num];
            continue;
        }
        int tmp = 0;
        for(auto p : primes){
            while(num % p == 0){
                num /= p;
                tmp++;
            }
            if(num == 1) break;
        }
        cnt += tmp;
        cache[num_c] = tmp;
    }
    return cnt;
}

int main() {
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios::sync_with_stdio(false);
    constexpr auto primes = get_primes<1229>();

    int T;
    std::cin >> T;

    for(int t=1; t<=T; ++t){
        int row, col;
        std::cin >> row >> col;
        std::vector<int> v(col);

        int gn = 0;
        while(row--){
            for(auto &i : v) std::cin >> i;
            gn ^= grundy(primes, v);
        }

        if(gn) std::cout << "Case #" << t << ": YES\n";
        else std::cout << "Case #" << t << ": NO\n";
    }

    return 0;
}