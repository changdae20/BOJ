#include <bits/stdc++.h>

int main(){
    
    int N;
    std::cin >> N;
    while(N--){
        std::string str;
        std::cin >> str;
        if(str.size() % 2){
            std::cout << "NO\n";
            continue;
        }
        std::stack<char> s;
        bool valid = true;
        for(char c : str){
            switch(c){
                case '(':
                    s.push(c);
                    break;
                case ')':
                    if(s.size()) s.pop();
                    else{
                        valid = false;
                        break;
                    }
                    break;
                default:
                    valid = false;
                    break;
            }
            if(!valid) break;
        }
        std::cout << (valid&&s.empty() ? "YES\n" : "NO\n");
    }
    return 0;
}