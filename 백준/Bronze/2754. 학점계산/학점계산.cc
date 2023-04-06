#include <iostream>
#include <vector>
#include <string>

int main(){
    #ifndef BOJ
    freopen("input.txt", "r", stdin);
    #endif

    std::string grade;
    std::cin >> grade;

    // A+: 4.3, A0: 4.0, A-: 3.7
    // B+: 3.3, B0: 3.0, B-: 2.7
    // C+: 2.3, C0: 2.0, C-: 1.7
    // D+: 1.3, D0: 1.0, D-: 0.7
    // F: 0.0

    if(grade == "A+") std::cout << "4.3";
    else if(grade == "A0") std::cout << "4.0";
    else if(grade == "A-") std::cout << "3.7";
    else if(grade == "B+") std::cout << "3.3";
    else if(grade == "B0") std::cout << "3.0";
    else if(grade == "B-") std::cout << "2.7";
    else if(grade == "C+") std::cout << "2.3";
    else if(grade == "C0") std::cout << "2.0";
    else if(grade == "C-") std::cout << "1.7";
    else if(grade == "D+") std::cout << "1.3";
    else if(grade == "D0") std::cout << "1.0";
    else if(grade == "D-") std::cout << "0.7";
    else if(grade == "F") std::cout << "0.0";
}