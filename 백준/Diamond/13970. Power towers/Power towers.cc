#include <numeric>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>

using uLL = unsigned long long;

uLL MOD;


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

std::pair<uLL, bool> ans(std::vector<uLL> vec, uLL M) {
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


int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	uLL Q;
	std::cin >> Q >> MOD;

	while (Q--) {
		uLL N, x;
		std::cin >> N;
		std::vector<uLL> vec;
		vec.reserve(N);
		int one_idx = -1;
		while (N--) {
			std::cin >> x;
			if (x == 1 && one_idx == -1) one_idx = vec.size();
			vec.push_back(x);
		}
        
		if (one_idx != -1) vec.erase(vec.begin() + one_idx, vec.end());
		if (vec.size()) std::reverse(vec.begin(), vec.end());
		std::cout << ans(vec, MOD).first << '\n';
	}


	return 0;
}