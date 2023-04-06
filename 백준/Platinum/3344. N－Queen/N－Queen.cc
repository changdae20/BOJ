#include <bits/stdc++.h>

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;

    // EVEN
    for(int i=2; i<=N; i+=2){
        if(N%6 == 3 && i==2) continue;
        std::cout << i << '\n';
    }
    if(N%6==3) std::cout << "2\n";

    // ODD
    if(N%6==2) std::cout << "3\n1\n";
    for(int i=1; i<=N; i+=2){
        if(N%6 == 2 && i<=5) continue;
        if(N%6 == 3 && i<=3) continue;
        std::cout << i << '\n';
    }
    if(N%6==2) std::cout << "5\n";
    if(N%6==3) std::cout << "1\n3\n";



    return 0;
}