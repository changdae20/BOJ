#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

int main(int argc, char* argv[]) {
    #ifndef BOJ
    freopen(argv[1], "r", stdin);
    #endif
    fastio;
	
	int N;
    std::cin >> N;

    std::vector<int> arr(N);
    for(auto& el : arr) std::cin >> el;
    auto it = arr.begin();
    int count = 0;
    while(it!=arr.end()){
        ++count;
        if(it!=arr.end() && (*std::next(it) < *it)){
            while(it!=arr.end() && ((*std::next(it)) < *(it))){
                ++it;
            }
        }
        if(it != arr.end()) ++it;
    }
    std::cout << count << std::endl;
    return 0;
}