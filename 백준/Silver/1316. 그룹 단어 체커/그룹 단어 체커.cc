#include <bits/stdc++.h>


int main(int argc, char** argv){
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios_base::sync_with_stdio(false);

    #ifndef BOJ
    freopen(argv[1], "r", stdin);
    #endif

    int Q;

    std::cin >> Q;

    std::string s;
    int ans = 0;
    while(Q--){
        bool d[26] = {false, };
        std::cin >> s;
        for(auto it = s.begin(); it != s.end(); ++it){
            if(it==std::prev(s.end(),1) || *(std::next(it,1)) != *it){
                if(d[*it-'a']){
                    break;
                }
                d[*it-'a'] = true;
            }
            if(it==std::prev(s.end(),1)){ // 마지막까지 통과
                ans++;
            }
        }
    }
    std::cout << ans << std::endl;
    return 0;
}