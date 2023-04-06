#include <bits/stdc++.h>

int main( int argc, char *argv[] ) {
#ifndef BOJ
    freopen( argv[ 1 ], "r", stdin );
#endif

    unsigned long long T;
    std::cin >> T;
    for(int t=1; t<=T; ++t) {
        std::vector<int> v;
        v.reserve(100000);

        int N, x;
        std::cin >> N;
        
        while(N--){
            std::cin >> x;
            v.push_back(x);
        }

        int maxx = 0;
        int ans = 0;
        auto front = v.begin();
        auto back = v.end() - 1;

        while(front != back){
            if(*front > *back){ // 뒤에거부터 serve
                if(maxx <= *back){
                    maxx = *back;
                    ++ans;
                }
                --back;
            }else if(*front <= *back){ // 앞에거부터 serve
                if(maxx <= *front){
                    maxx = *front;
                    ++ans;
                }
                ++front;
            }
        }

        std::cout << "Case #" << t << ": " << ++ans << '\n';
    }

    return 0;
}