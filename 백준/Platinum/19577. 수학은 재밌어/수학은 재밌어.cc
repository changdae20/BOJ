#include <bits/stdc++.h>

int phi(int n){
	int ans = n;
	std::vector<int> primes;
	if(n%2 == 0){
		primes.push_back(2);
		while(n%2 == 0) n /= 2;
	}

	for(int p = 3; p*p <= n; p += 2){
		if(n%p == 0){
			primes.push_back(p);
			while(n%p == 0) n /= p;
		}
	}

	if(n>1) primes.push_back(n);

	for(auto& p : primes){
		ans = ans - ans / p;
	}
	return ans;
}

std::vector<int> divisor(int N){
	std::vector<int> ans;
	for(int i=1; i*i<=N; ++i){
		if(N%i == 0){
			ans.push_back(i);
			if(i*i != N) ans.push_back(N/i);
		}
	}
	std::sort(ans.begin(), ans.end());
	return ans;
}

int main(int argc, char* argv[]){
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios::sync_with_stdio(false);

	int N;
	std::cin >> N;

	auto candidates = divisor(N);

	for(auto& div : candidates){
		if(div * phi(div) == N){
			std::cout << div << std::endl;
			return 0;
		}
	}

	std::cout << -1 << std::endl;
	return 0;
}