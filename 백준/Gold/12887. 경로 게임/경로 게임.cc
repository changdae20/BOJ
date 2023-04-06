#include <bits/stdc++.h>

int main(int argc, char *argv[]){
    #ifndef BOJ
    freopen(argv[1], "r", stdin);
    #endif

    int N;
    std::cin >> N;

    std::vector<std::array<bool,2>> arr(N, std::array<bool, 2>({false, false}));

    for(int i=0;i<N;++i){
        char a;
        std::cin >> a;
        if(a=='.') arr[i][0] = true;
    }
    for(int i=0;i<N;++i){
        char a;
        std::cin >> a;
        if(a=='.') arr[i][1] = true;
    }

    int ans = 0;

    auto it = std::find_if( arr.begin(), arr.end(), [](std::array<bool,2> a){return !(a[0] && a[1]);} );
    ans += std::distance(arr.begin(), it);
    while(it != arr.end()){
        auto it2 = std::find_if( std::next(it,1) , arr.end(), [](std::array<bool,2> a){return !(a[0] && a[1]);} );
        
        if( it2 != arr.end() && ((it->at(0) && it2->at(0)) || (it->at(1) && it2->at(1)))){
            ans += std::distance(it, it2 )-1;
        }else if(it2 == arr.end()){
            ans += std::distance(it, it2) - 1;
        }else{
            ans += std::distance(it, it2)-2;
        }
        it = it2;
    }

    std::cout << ans << '\n';

    return 0;
}