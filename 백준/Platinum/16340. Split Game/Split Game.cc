#include <bits/stdc++.h>

std::vector<int> grundy(2001, 0);

void build_grundy(){
    for(int x = 1; x <= 2000; ++x){
        std::vector<int> mex;

        for(int pile = 1; pile < x; ++pile){
            int moong_taeng_e = x / pile;
            int remain = x % pile;

            int g = 0;
            if(moong_taeng_e&1){
                g ^= grundy[pile];
            }
            g ^= grundy[remain];
            mex.push_back(g);
        }
        // sort and unique
        std::sort(mex.begin(), mex.end());
        mex.erase(std::unique(mex.begin(), mex.end()), mex.end());
        grundy[x] = std::distance(mex.begin(), std::find_if(mex.begin(), mex.end(), [t=0](auto &el) mutable {return el != t++;}));
    }
}

int main(){
    build_grundy();
    
    unsigned long long ans = 0;
    int N, x;

    std::cin >> N;

    while(N--){
        std::cin >> x;
        ans ^= grundy[x];
    }

    std::cout << (ans ? "First" : "Second") << std::endl;

    return 0;
}