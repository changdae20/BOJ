#include <bits/stdc++.h>

std::map<unsigned long long, int> cache;

int grundy(unsigned long long K, unsigned long long N){
	if( K >= N ) return 0;
	if( auto it = cache.find(K); it != cache.end() ) return it->second;

	std::set<int> s;
	for(int i=2; i<=9; ++i){
		s.insert(grundy(i*K, N));
	}

	int mex = 0;
	while(s.count(mex)) ++mex;
	cache[K] = mex;
	return mex;
}

int main() {
	unsigned long long N;
	while(true){
		std::cin >> N;
		if(std::cin.eof()){
			break;
		}
		
		cache.clear();

		if( grundy(1, N) )
			std::cout << "Baekjoon wins.\n";
		else
			std::cout << "Donghyuk wins.\n";
	}
	return 0;
}