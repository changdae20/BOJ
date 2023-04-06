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
    for (int x = 0; x < n; ++x){
        std::vector<int> mex;

        if(x&1){
            mex.push_back(v[0]);
        }
        for(int i=1; x-2*i>0;++i){
            mex.push_back(v[x-2*i]);
        }
        // sort and unique
        std::sort(mex.begin(), mex.end());
        mex.erase(std::unique(mex.begin(), mex.end()), mex.end());
        v[x] = std::distance(mex.begin(), std::find_if(mex.begin(), mex.end(), [t=0](auto &el) mutable {return el != t++;}));
    }

    // save to file as mex_k.txt
    if(save){
        std::ofstream ofs("mex.txt");
        for (int x = 0; x < n; ++x){
            ofs << std::setw(5) << v[x];
            ofs << std::endl;
        }
        std::cout << "Saved as " << "mex.txt" << std::endl;
    }

    // check runtime
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;

    std::cout << "Elapsed time: " << elapsed_seconds.count() << "s" << std::endl;

    return v;
}

int grundy(int x){
    if (x == 0) return 0;
    if (x == 1) return 1;
    if (x == 2) return 0;
    if (x == 3) return 2;
    if((x&3) == 0) return (x/4) * 2 - 1;
    if((x&3) == 1) return (x/4) * 2 + 1;
    if((x&3) == 2) return x/4 * 2;
    if((x&3) == 3) return (x/4) * 2 + 2;
}

void check(int n){
    auto v = bake(n);
    for (int i = 0; i < n; ++i){
        assert(v[i]== grundy(i));
    }
}

int main(){
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios_base::sync_with_stdio(false);

    #ifndef BOJ
    freopen("input.txt", "r", stdin);
    #endif

    int N;
    std::cin >> N;
    int k;
    int ans = 0;
    while(N--){
        std::cin >> k;
        ans ^= grundy(k);
    }

    std::cout << (ans ? "koosaga" : "cubelover") << std::endl;
    
    return 0;
}