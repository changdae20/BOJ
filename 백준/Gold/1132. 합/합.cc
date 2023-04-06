#include <regex>
#include <string>
#include <iostream>
#include <numeric>
#include <fstream>
#include <utility>
#include <algorithm>

int main() {
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios::sync_with_stdio(0);

    #ifndef BOJ
    freopen("input.txt","r",stdin);
    #endif

    // (A,0), (B,0), ... , (J,0) 으로 초기화
    std::vector<std::pair<char, unsigned long long>> dict;
    for(char c = 'A'; c<='J'; c++){
        dict.push_back(std::pair(c,0));
    }

    int N;
    std::cin >> N;

    std::string buf;
    std::vector<unsigned long long> pow_dict = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000, 100000000000, 1000000000000};
    std::vector<char> start_letters;
    while(N--){
        std::cin >> buf;
        start_letters.push_back(buf[0]);
        for(size_t i=0; i<buf.length(); ++i){
            dict[static_cast<int>(buf[i]) - static_cast<int>('A')].second += pow_dict[buf.length()-i-1];
        }
    }

    std::sort(dict.begin(), dict.end(), [](auto &a, auto& b){return a.second > b.second;});

    auto iter = std::find_if(dict.rbegin(), dict.rend(), [&start_letters](auto& el){
        return std::find(start_letters.begin(), start_letters.end(), el.first) == start_letters.end();
    });

    if(iter != dict.rend()){
        dict.erase(std::next(iter).base());
    }

    unsigned long long sum = std::accumulate(dict.begin(), dict.end(), 0uLL, [n=9](auto& a, auto &b) mutable {
        return a + b.second*(n--);
    });

    std::cout << sum << std::endl;

    return 0;
}