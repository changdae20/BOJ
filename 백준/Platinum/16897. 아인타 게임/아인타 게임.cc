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


int grundy(int x, int y, int k){
    if(k==1){
        if((x&1) == (y&1)) return 2-2*(x&1);
        else return 2-2*(std::min<>(x,y)&1) + 1;
    }
    if (x <= k || y <= k) return (x+y)&1;
    else if(x==y){
        return (x%(k+1)==0) ? 2 : ((x/(k+1))&1);
    }else{
        int small = std::min<>(x, y);
        int big = std::max<>(x, y);

        switch( (small%(k+1)==0) ? 2 : ((small/(k+1))&1) ){
            case 0 : return ((big-small)&1);
            case 1 : return 1-((big-small)&1);
            case 2 : return 2 + ((big-small)&1);
        }
    }

    return 0;
}

int main(){
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios_base::sync_with_stdio(false);
    
    int N;
    std::cin >> N;
    int row,col,k;
    while(N--){
        std::cin >> k >> row >> col;
        if(grundy(row, col, k)){
            std::cout << "koosaga\n";
        }else{
            std::cout << "cubelover\n";
        }
    }

    return 0;
}