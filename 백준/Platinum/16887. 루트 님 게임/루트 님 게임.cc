#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>
#include <chrono>
#include <assert.h>

std::vector<int> bake(int n, bool save = true){

    // check runtime
    auto start = std::chrono::system_clock::now();

    std::vector<int> v(n,0);

    // fill the array with mex (grundy number)
    for (int x = 1; x < n; ++x){
        std::vector<int> mex;

        // check i^1/4 to i^1/2
        for (int y = 1; y*y <= x; ++y){
            if(y>=x) continue;
            if (y<x && y*y<x && y*y*y<x && y*y*y*y < x) continue;
            mex.push_back(v[y]);
        }

        // sort and unique
        std::sort(mex.begin(), mex.end());
        mex.erase(std::unique(mex.begin(), mex.end()), mex.end());
        v[x] = std::distance(mex.begin(), std::find_if(mex.begin(), mex.end(), [t=0](auto &el) mutable {return el != t++;}));
    }

    // save to file as mex_{piece}.txt
    if(save){
        std::ofstream ofs("mex.txt");
        for (int i = 0; i < n; ++i){
            ofs << v[i] << std::endl;
        }
        std::cout << "Saved as " << "mex.txt" << std::endl;
    }

    // check runtime
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;

    std::cout << "Elapsed time: " << elapsed_seconds.count() << "s" << std::endl;

    return v;
}

unsigned long long grundy(unsigned long long i){
    if(i<4) return 0;
    else if(i<16) return 1;
    else if(i<82) return 2;
    else if(i<6724) return 0;
    else if(i<50626) return 3;
    else if(i<2562991876) return 1;
    else return 2;
}

void check(int n){
    auto v = bake(n, false);
    for (int i = 0; i < n; ++i){
        assert(v[i] == grundy(i));
    }
}

int main(){
    #ifndef BOJ
    freopen("input.txt", "r", stdin);
    #endif

    unsigned long long N;
    std::cin >> N;
    unsigned long long row;
    unsigned long long ans = 0;
    while(N--){
        std::cin >> row;
        ans ^= grundy(row);
    }
    if(ans){
        std::cout << "koosaga" << std::endl;
    }else{
        std::cout << "cubelover" << std::endl;
    }

    return 0;
}