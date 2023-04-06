#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

bool is_valid(std::string& s){
    std::regex reg("(-?[0-9]+)([-+*])(-?[0-9]+)=(-?[0-9]+)");
    if( !std::regex_match(s, reg) ) return false;
    std::sregex_token_iterator it(s.begin(), s.end(), reg, {1,2,3,4});

    int num1 = std::stoi(*it);
    char op = std::string(*std::next(it))[0];
    int num2 = std::stoi(*std::next(it,2));
    int result = std::stoi(*std::next(it,3));

    // leading zero는 없어야 하므로, to_string과 파싱한 값이 다시 일치해야 한다.
    // (std::stoi와 std::to_string이 완벽하게 역함수 관계에 있어야 Leading zeros가 없다는 뜻이다)
    if(std::to_string(num1) != *it || std::to_string(num2) != *std::next(it,2) || std::to_string(result) != *std::next(it,3)) return false;

    switch(op){
        case '+':
            return num1+num2==result;
        case '-':
            return num1-num2==result;
        case '*':
            return num1*num2==result;
    }
    return false;
}
int main(int argc, char* argv[]) {
    #ifndef BOJ
    freopen(argv[1], "r", stdin);
    #endif
    fastio;

    int T;
    std::cin >> T;
    while(T--){
        std::string s;
        std::cin >> s;
        int i;
        for(i = 0; i<=9; ++i){
            if(std::find(s.begin(), s.end(), '0'+i) != s.end()) continue;
            auto replaced = std::regex_replace(s, std::regex("\\?"), std::to_string(i));
            if(is_valid(replaced)){
                std::cout << i << '\n';
                break;
            }
        }
        if(i > 9) std::cout << -1 << '\n';
    }
	return 0;
}