#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>

int main() {
	std::vector<int> v;
	std::vector<int> a{ 6,3,2,1,2 };
	int n;
	for (int i = 0; i < 5; i++) {
		std::cin >> n;
		v.push_back(n);
	}
	std::cout << std::inner_product(a.begin(), a.end(), v.begin(), 0) << ' ';
	v.clear();
	for (int i = 0; i < 5; i++) {
		std::cin >> n;
		v.push_back(n);
	}
	std::cout << std::inner_product(a.begin(), a.end(), v.begin(), 0) << std::endl;
	return 0;
}