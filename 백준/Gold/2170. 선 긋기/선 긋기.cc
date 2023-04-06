#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <functional>
#include <utility>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	#endif
	int N;
	int a,b;
	std::vector<std::pair<int,int>> v;
	std::cin >> N;
	v.reserve(N);
	while(N--){
		std::cin >> a >> b;
		v.emplace_back(a,b);
	}
	std::sort(v.begin(),v.end(),[](const auto& c, const auto& d){
		return c.first < d.first;
	});

	long long length = 0;
	int range = INT32_MIN;

	for(const auto& [start, end] : v){
		if(range<start){ // 새로운 스위핑 시작
			length += range;
			length -= start;
		}
		range = std::max(range,end);
	}
	length += range;
	length -= INT32_MIN;

	std::cout << length << '\n';

	return 0;
}