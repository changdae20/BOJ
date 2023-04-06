#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
	int N,NN;
	std::cin >> N;
	NN = N;
	std::vector<int> v;
	v.reserve(N);
	int i;
	while(N--){
		std::cin >> i;
		v.push_back(i);
	}

	std::cout << std::accumulate(v.begin(),v.end(),0.0)*100.0 /NN / (*std::max_element(v.begin(),v.end())) << std::endl;
	return 0;
}