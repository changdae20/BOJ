#include <iostream>

int main(){
    unsigned long long n;
    std::cin >> n;
    std::cout << ((n%7uLL == 0uLL || n%7uLL == 2uLL) ? "CY" : "SK");
    return 0;
}