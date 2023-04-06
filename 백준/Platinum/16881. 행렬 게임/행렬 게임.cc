#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    std::cin.tie( nullptr );
    std::cout.tie( nullptr );
    std::ios_base::sync_with_stdio( false );
    
	int row,col;
	std::cin >> row >> col;
	unsigned int ans = 0;

	std::vector<unsigned int> values(col);
	while(row--){
		unsigned int gn = 0u;
		for(auto& el : values){
			std::cin >> el;
		}
		for(auto it = values.rbegin(); it!=values.rend(); ++it){
			gn = (*it) - ((*it)<=gn);
		}
		ans ^= gn;
	}
	if(ans) std::cout << "koosaga\n";
	else std::cout << "cubelover\n";
    return 0;
}