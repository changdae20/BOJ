#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
	int N;
	std::cin >> N;

	int i = 1;
	int c = 1;
	while(N>i){
		i += (6*c);
		++c;
	}
	std::cout << c << std::endl;
	return 0;
}