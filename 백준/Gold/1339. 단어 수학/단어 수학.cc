#include <regex>
#include <string>
#include <iostream>
#include <numeric>
#include <fstream>
#include <utility>
#include <algorithm>
#include <set>
#include <map>

void permute(std::vector<std::string>& words){
    std::set<char> s;

    for(auto& word : words){
        for(auto& c : word){
            s.insert(c);
        }
    }

    std::map<char, char> permu;

    for(auto it = s.begin(); it != s.end(); ++it){
        permu[*it] = std::distance(s.begin(), it);
    }

    for(auto& word : words){
        for(auto& c : word){
            c = permu[c] + 'A';
        }
    }

    return;
}
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
    std::vector<std::string> words(N);
    std::string buf;
    std::vector<unsigned long long> pow_dict = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000, 100000000000, 1000000000000};
    bool start_letters[10] = {false, false, false, false, false, false, false, false, false, false};

    // 자릿수를 고려하여 빈도수를 계산, 시작 문자들 저장
    for(auto& word : words){
        std::cin >> word;
    }

    permute(words);

    for(auto& buf : words){
        start_letters[static_cast<int>(buf[0]) - static_cast<int>('A')] = true;
        for(size_t i=0; i<buf.length(); ++i){
            dict[static_cast<int>(buf[i]) - static_cast<int>('A')].second += pow_dict[buf.length()-i-1];
        }
    }

    // 빈도수 대로 정렬
    std::sort(dict.begin(), dict.end(), [](auto &a, auto& b){return a.second > b.second;});

    // 시작문자가 아닌 수 중에서 빈도수가 최소인 알파벳 구하고
    auto iter = std::find_if(dict.rbegin(), dict.rend(), [&start_letters](auto& el){
        return start_letters[static_cast<int>(el.first) - static_cast<int>('A')]==false;
    });

    // 없앤다
    if(iter != dict.rend()){
        dict.erase(std::next(iter).base());
    }

    // 이후 9 8 7 6 5 4 3 2 1 순서로 곱해가면서 더해준다
    unsigned long long sum = std::accumulate(dict.begin(), dict.end(), 0uLL, [n=9](auto& a, auto &b) mutable {
        return a + b.second*(n--);
    });

    // 정답 출력
    std::cout << sum << std::endl;

    // 생각해보니까 sort를 오름차순으로 하고 find_if를 정방향 반복자로 구하면 erase를 쉽게 할 수 있는데, 왜 굳이 반대로 했는지 잘 모르겠다.

    return 0;
}