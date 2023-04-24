#include <bits/stdc++.h>

int main(){
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int T;
    std::cin >> T;
    while(T--){
        int N;
        std::cin >> N;
        std::set<std::string> s;
        std::string s_;
        while(N--){
            std::cin >> s_;
            s.insert(s_);
        }
        std::cout << s.size() << '\n';
    }
    return 0;
}