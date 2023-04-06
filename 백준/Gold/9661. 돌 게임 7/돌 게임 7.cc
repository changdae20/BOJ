#include <iostream>
#include <vector>
#include <algorithm>
#include <regex>
#include <string>
#include <numeric>

int main(){
    unsigned long long n;
    std::cin >> n;
    std::cout << ((n%5uLL == 0uLL || n%5uLL == 2uLL) ? "CY" : "SK");
    return 0;
}