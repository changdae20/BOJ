#include <iostream>

int main() {
    std::cin.tie( nullptr );
    std::cout.tie( nullptr );
    std::ios_base::sync_with_stdio( false );
    unsigned int N,M,K,T;
	std::cin >> T;
	while(T--){
		std::cin >> N >> M >> K;
		if(std::max(N,M)<=2*K-1){ //좌상단, 우하단이 중앙에서 겹치는 경우 그 칸에 놓으면 선공이 무조건 이김
			std::cout << "Yuto\n";
		}else if((N*M)&1){
			std::cout << "Yuto\n";
		}else{
			std::cout << "Platina\n";
		}
	}
    return 0;
}