#include <bits/stdc++.h>

int grundy(int N){
    int gn = 1;
    while(N){
        if(N&1)
            return gn;
        else{
            ++gn;
            N >>= 1;
        }
    }
}

int main(){
    std::cin.tie(nullptr);std::cout.tie(nullptr);std::ios_base::sync_with_stdio(false);
    int B,G; std::cin >> B >> G;
    std::cout << ((grundy(B)^grundy(G)) ? "A player wins" : "B player wins") << std::endl;
    return 0;
}