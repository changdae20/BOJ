#include <iostream>
#include <vector>
#include <string>

int main(){
    #ifndef BOJ
    freopen("input.txt", "r", stdin);
    #endif

    std::string a;
    std::cin >> a;

    for(auto it = a.begin(); it != a.end(); ++it){
        if(*it <= 'Z'){
            std::cout << static_cast<char>((*it - 'A' + 'a'));
        }
        else{
            std::cout << static_cast<char>((*it - 'a' + 'A'));
        }
    }
}