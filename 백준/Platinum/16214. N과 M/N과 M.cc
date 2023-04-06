#include <cmath>
#include <iostream>

using uLL = unsigned long long;

uLL mod_pow(uLL A, uLL B, uLL M) {
	if (B == 0) return 1LL;
	else if (B == 1) return A % M;

	if (B&1) {
		uLL half = mod_pow(A, B / 2, M);
		return (((half*half) % M)*A) % M;
	}
	else {
		uLL half = mod_pow(A, B / 2, M);
		return (half*half) % M;
	}
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

uLL ans(uLL N, uLL M) {
	if (M == 1) return 0;
	uLL p = phi(M);
	uLL a = ans(N, p);
	return mod_pow(N, a + p, M);
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	uLL T;
	uLL N, M;
	std::cin >> T;
	while (T--) {
		std::cin >> N >> M;
		std::cout << ans(N, M) << "\n";
	}
}