#include <iostream>
#include <array>

int main() {
	std::array<int, 11> arr{1,1,2,4,7,13,24,44,81,149,274};
	int T,N;
	std::cin >> T;
	while(T--){
		std::cin >> N;
		std::cout << arr[N] << '\n';
	}
	return 0;
}