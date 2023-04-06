#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
int main() {
	int T;
	std::cin >> T;

	while(T--){
		std::string s;
		std::cin >> s;
		int streak = 1;
		int score = 0;
		for(auto& el : s){
			if(el=='O'){
				score+=streak;
				streak++;
			}else{
				streak=1;
			}
		}
		std::cout << score << std::endl;
	}
	return 0;
}