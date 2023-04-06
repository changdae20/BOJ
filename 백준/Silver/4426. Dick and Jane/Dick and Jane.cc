#include <bits/stdc++.h>

int main(){
#ifndef BOJ
    freopen("sample/input_1.txt", "r", stdin);
#endif
    std::cin.tie(NULL);
    std::ios::sync_with_stdio( false );
    std::cout.tie(NULL);

    int s, p, y, j;
    while(true){
        std::cin >> s >> p >> y >> j;
        if(std::cin.eof()) break;
        int q = (12+j-p-y)/3;
        int r = (12+j-p-y)%3;

        switch(r){
            case 0:
                std::cout << y+q << ' ' << p+q << ' ' << q << '\n';
                break;
            
            case 1:
                if(s+p==y){
                    std::cout << (y+1)+q << ' ' << p+q << ' ' << q << '\n';
                }else{
                    std::cout << y+q << ' ' << (p+1)+q << ' ' << q << '\n';
                }
                break;
            case 2:
                std::cout << (y+1)+q << ' ' << (p+1)+q << ' ' << q << '\n';
                break;
        }
    }
    return 0;
}