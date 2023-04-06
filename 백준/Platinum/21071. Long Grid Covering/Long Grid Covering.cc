#include <iostream>
#include <vector>
#include <functional>
#include <utility>
#include <algorithm>
#include <numeric>
#include <assert.h>

using uLL = unsigned long long;
uLL MOD = 1000000007;

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
	assert(a[0].size() == b.size());
	std::vector<std::vector<uLL>> ans(a.size(), std::vector<uLL>(b[0].size(), 0uLL));
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b[0].size(); j++) {
			ans[i][j] = std::inner_product(a[i].begin(), a[i].end(), b.begin(), 0LL, [M](auto el1, auto el2) {return (el1 + el2) % M; }, [j, M](auto el, auto& col) {return (el * col[j]) % M; }) % M;
		}
	}
	return ans;
}

auto mat_pow(std::vector<std::vector<uLL>> mat, uLL N, uLL M = MOD) {
	std::vector<std::vector<uLL>> ans(mat[0].size(), std::vector<uLL>(mat.size(), 0uLL));
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


uLL ans(uLL N) {
	if (N == 0) return 1;
	else if (N == 1) return 1;
	else if (N == 2) return 3;
	else if (N == 3) return 10;
	auto sugar = mat_pow(std::vector<std::vector<uLL>>{ { 1uLL, 2uLL, 6uLL, 1uLL , 0uLL, MOD-1 }, { 1uLL, 0uLL, 0uLL, 0uLL, 0uLL, 0uLL }, { 0uLL, 1uLL, 0uLL, 0uLL, 0uLL, 0uLL }, { 0uLL, 0uLL, 1uLL, 0uLL, 0uLL, 0uLL }, { 0uLL, 0uLL, 0uLL, 1uLL, 0uLL, 0uLL }, { 0uLL, 0uLL, 0uLL, 0uLL, 1uLL, 0uLL } }, N-3 );
	auto basket = std::vector<std::vector<uLL>>{ { 10uLL }, { 3uLL }, { 1uLL }, { 1uLL }, { 0uLL }, { 0uLL } };
	auto banana = matmul(sugar, basket);

	return banana[0][0];
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int Q;
	std::cin >> Q;

	while (Q--) {
		uLL N;
		std::cin >> N;
		std::cout << ans(N) << '\n';
	}
	return 0;
}