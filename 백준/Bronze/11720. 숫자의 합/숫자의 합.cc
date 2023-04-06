#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
int main() {
	int N;
	std::cin >> N;
	std::string s;
	std::cin >> s;
	std::cout << std::accumulate(s.begin(),s.end(),0,[](auto& a, auto& b){return a + (b-'0');}) << '\n';
	return 0;
}