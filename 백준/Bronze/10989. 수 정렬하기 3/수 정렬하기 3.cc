#include <bits/stdc++.h>

int main(){
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    int N;
    std::cin >> N;

    std::vector<int> v(10001,0);

    int a;
    for(int i=0; i<N; ++i){
        std::cin >> a;
        ++v[a];
    }

    for(int i=0; i<=10000;++i){
        for(int j=0; j<v[i]; ++j){
            std::cout << i << '\n';
        }
    }
}