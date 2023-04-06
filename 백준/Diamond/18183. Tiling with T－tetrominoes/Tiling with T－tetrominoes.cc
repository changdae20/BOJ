#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <functional>

using uLL = unsigned long long;
uLL MOD = 998244353;

uLL mod_pow(uLL A, uLL B, uLL M = MOD) {
	if (B == 0) return 1LL;
	uLL ans = 1uLL;
	A %= M;
	while (B > 0) {
		if (B & 1) {
			ans = (ans * A) % M;
		}
		B >>= 1;
		A = (A * A) % M;
	}
	return ans;
}

auto matmul(std::vector<std::vector<uLL>> a, std::vector<std::vector<uLL>> b, uLL M = MOD) {
	std::vector<std::vector<uLL>> ans(a.size(), std::vector<uLL>(b[0].size(), 0uLL));
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b[0].size(); j++) {
			ans[i][j] = std::inner_product(a[i].begin(), a[i].end(), b.begin(), 0LL, [M](auto el1, auto el2) {return (el1 + el2) % M; }, [j,M](auto el, auto& col) {return (el*col[j]) % M; }) % M;
		}
	}
	return ans;
}

auto mat_pow(std::vector<std::vector<uLL>> mat, uLL N, uLL M = MOD) {
	std::vector<std::vector<uLL>> ans(mat.size(), std::vector<uLL>(mat.size(),0uLL));
	for (int i = 0; i < ans.size(); i++) ans[i][i] = 1uLL;

	while (N > 0) {
		if (N & 1) {
			ans = matmul(ans, mat);
		}
		N >>= 1;
		mat = matmul(mat, mat);
	}

	return ans;
}

uLL ans(uLL N, uLL M) {
	if (M == 1) {
		auto temp = mod_pow(3uLL, N-1);
		return (temp * 2) % MOD;
	} else if(M == 2) {
		auto sugar = mat_pow(std::vector<std::vector<uLL>>{ {18uLL, 9uLL}, {16uLL,14uLL} }, N - 1);
		auto basket = std::vector<uLL>{ 2uLL, 1uLL };
		uLL banana = std::inner_product(basket.begin(), basket.end(), sugar.begin(), 0uLL, std::plus<>(), [](auto& coeff, auto& row) {
			return coeff * std::accumulate(row.begin(), row.end(),0uLL);
		});
		uLL apple = mod_pow(mod_pow(2uLL, MOD - 2), MOD + N - 3);

		return (banana*apple)%MOD;

	} else if (M == 3uLL) {
		auto sugar = mat_pow(std::vector<std::vector<uLL>>{ {108uLL, 54uLL, 0uLL, 54uLL, 27uLL}, { 96uLL, 84uLL, 0uLL, 48uLL, 42uLL }, { 96uLL, 48uLL, 12uLL, 48uLL, 48uLL }, { 96uLL, 48uLL, 0uLL, 84uLL, 42uLL }, { 80uLL, 64uLL, 8uLL, 64uLL, 96uLL } }, N - 1);
		auto basket = std::vector<uLL>{ 4uLL, 2uLL, 0uLL, 2uLL, 1uLL };
		uLL banana = std::inner_product(basket.begin(), basket.end(), sugar.begin(), 0uLL, std::plus<>(), [](auto& coeff, auto& row) {
			return coeff * std::accumulate(row.begin(), row.end(), 0uLL);
		}) % MOD;
		uLL apple = mod_pow(mod_pow(2uLL, MOD - 2), MOD + 2*N - 4);

		return (banana*apple) % MOD;
	} else {
		return 0uLL;
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	uLL N, M;
	std::cin >> N >> M;

	if ((N | M) & 3uLL) {
		std::cout << 0 << std::endl;
	}
	else {
		std::cout << ans(N >> 2, M >> 2) << std::endl;
	}
	return 0;
}