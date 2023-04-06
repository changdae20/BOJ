#include <numeric>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>

using uLL = unsigned long long;

uLL MOD = 1000000007;

uLL mod_pow(uLL A, uLL B, uLL M) {
	if (B == 0) return 1LL;
    else if(B == 1) return A%M;
	uLL ans = 1uLL;
	while (B > 0) {
		if (B & 1) {
			ans = ans * A % M;
		}
		B >>= 1;
		A = A * A % M;
	}
	return ans;
}

uLL phi(uLL N) {
	uLL ans = N;
	for (uLL p = 2; p <= std::pow(N, 0.5f); p++) {
		if (N%p == 0) {
			ans -= ans / p;
			while (N%p == 0) N /= p;
		}
		if (N < p) break;
	}
	if (N > 1) ans -= ans / N;
	return ans;
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	uLL N,x;
	std::cin >> N;
    std::vector<uLL> vec;
	while (N--) {
		std::cin >> x;
		vec.push_back(x);
	}
    std::sort(vec.begin(),vec.end());
    int idx=0;
    std::cout << std::accumulate(vec.begin(),vec.end(),0uLL,[&idx,size=vec.size()](uLL sum, uLL& el) mutable{
        sum -= el*mod_pow(2,size-1-idx,MOD)%MOD;
        sum += el*mod_pow(2,idx,MOD)%MOD;
        idx++;
        return (sum+MOD)%MOD;
    })<<std::endl;


	return 0;
}