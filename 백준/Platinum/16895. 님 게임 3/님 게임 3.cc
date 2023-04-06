#include <bits/stdc++.h>

int main() {
    std::cin.tie( nullptr );
    std::cout.tie( nullptr );
    std::ios_base::sync_with_stdio( false );
    int N;
    std::cin >> N;
    std::vector<int> arr(N);
    int count = 0;
    int ans = 0;
    for(auto& el : arr){
        std::cin >> el;
        ans ^= el;
    }

    for(auto& el : arr){
        if((el^ans) < el) ++count;
    }

    std::cout << count << std::endl;

    return 0;
}