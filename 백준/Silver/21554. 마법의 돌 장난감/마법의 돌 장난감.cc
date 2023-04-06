#include <bits/stdc++.h>

int main(int argc, char** argv){
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios_base::sync_with_stdio(false);

    #ifndef BOJ
    freopen(argv[1], "r", stdin);
    #endif

    int N;
    std::cin >> N;

    std::vector<int> arr(N+1);

    arr[0] = 0;

    for(int i=1; i<=N; ++i){
        std::cin >> arr[i];
    }

    int count = 0;

    auto it = arr.begin();

    std::vector<std::pair<int, int>> ans;

    while(it != arr.end() || count > 100){
        if(*it == std::distance(arr.begin(), it)){
            ++it;
        }else{
            ++count;
            auto it2 = std::find(arr.begin(), arr.end(), std::distance(arr.begin(), it));
            ans.push_back({std::distance(arr.begin(),it), std::distance(arr.begin(),it2)});
            std::reverse(it, it2+1);
            ++it;
        }
    }

    if(count>100){
        std::cout << -1 << '\n';
    }else{
        std::cout << count << '\n';
        for(auto& [a,b] : ans){
            std::cout << std::min<>(a,b) << ' ' << std::max<>(a,b) << '\n';
        }
    }


    return 0;
}