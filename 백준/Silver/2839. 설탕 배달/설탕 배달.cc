#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
	int N;
	std::cin >> N;

	int i = N/5;

	while(i>=0){
		if((N - (5*i))%3==0){
			std::cout << i + ((N - (5*i))/3) << std::endl;
			return 0;
		}else{
			i--;
		}
	}
	std::cout << -1 << std::endl;
	return 0;
}