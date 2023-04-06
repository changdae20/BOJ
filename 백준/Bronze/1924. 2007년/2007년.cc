#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
	std::vector<int> days = {31,28,31,30,31,30,31,31,30,31,30};
	int m,d;
	std::cin >> m >> d;
	d = (std::accumulate(days.begin(),days.begin()+m-1,d)-1)%7;
	switch(d){
		case 0:
			std::cout << "MON\n";
			break;
		case 1:
			std::cout << "TUE\n";
			break;
		case 2:
			std::cout << "WED\n";
			break;
		case 3:
			std::cout << "THU\n";
			break;
		case 4:
			std::cout << "FRI\n";
			break;
		case 5:
			std::cout << "SAT\n";
			break;
		case 6:
			std::cout << "SUN\n";
			break;
	}
	return 0;
}