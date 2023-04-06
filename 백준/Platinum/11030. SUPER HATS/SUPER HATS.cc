#include <bits/stdc++.h>

using uLL = unsigned long long;

constexpr uLL MOD = 100000000;

std::pair<uLL, bool> mod_pow(uLL A, uLL B, uLL M) {
	if (B == 0) return std::pair(1LL, false);
	uLL ans = 1uLL;
	bool overed = false;
	while (B > 0) {
		if (B & 1) {
			if (ans*A >= M) overed = true;
			ans = ans * A % M;
		}
		B >>= 1;
		if (A*A >= M) overed = true;
		A = A * A % M;
	}
	return std::pair(ans, overed);
}

uLL phi(uLL N) {
	if (N == 1) return 0;
	if (N == 2) return 1;
	uLL ans = N;
	for (uLL p = 2; p*p <= N; p++) {
		if (N%p == 0) {
			ans -= ans / p;
			while (N%p == 0) N /= p;
		}
		if (N < p) break;
	}
	if (N > 1) ans -= ans / N;
	return ans;
}

std::pair<uLL, bool> ans(std::vector<uLL> &vec, uLL M) {
	if (vec.size() == 0) {
		return std::pair(1, false);
	}
	if (vec[vec.size() - 1] % M == 0) return std::pair(0, true);
	if (vec.size() == 2) {
		return mod_pow(vec[1], vec[0], M);
	}
	else if (vec.size() == 1) {
		return std::pair(vec[0] % M, vec[0] >= M);
	}
	else {
		uLL base = vec[vec.size() - 1];
		vec.erase(vec.end() - 1);
		uLL p = phi(M);
		auto[q, over] = ans(vec, p);
		if (over) return mod_pow(base, p + q, M);
		else if (q >= p) return mod_pow(base, p + (q%p), M);
		else return mod_pow(base, q, M);
	}
}

std::string fill_zero(uLL ans, uLL n){
    std::string filled = std::to_string(ans);
    std::string padding = std::string(n - filled.size(), '0');
    return (padding + filled);
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	uLL A,B;
	std::cin >> A >> B;

    std::vector<uLL> vec(B, A);
    
    auto [p, q] = ans(vec, MOD);
    if(q) std::cout << fill_zero(p, 8) << '\n';
    else std::cout << p << '\n';
	return 0;
}