#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

int main(int argc, char* argv[]) {
    #ifndef BOJ
    freopen(argv[1], "r", stdin);
    #endif
    fastio;
	
    int N;
    std::cin >> N;
    std::vector<std::pair<int, std::string>> v(N);
    for(auto& [age, name] : v) std::cin >> age >> name;
    std::stable_sort(v.begin(), v.end(), [](auto &a, auto &b){return a.first < b.first;});
    for(auto& [age, name] : v) std::cout << age << ' ' << name << '\n';

    return 0;
}