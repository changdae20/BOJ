#include <iostream>

int main(){
    int Q;
    std::cin >> Q;
    int A,B;
    int i = 0;
    while(Q--){
        std::cin >> A >> B;
        std::cout << "Case #" << ++i << ": " << A+B << '\n';
    }
    return 0;
}