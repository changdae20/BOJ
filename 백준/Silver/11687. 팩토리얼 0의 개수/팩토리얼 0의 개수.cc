#include <iostream>

int log5(int x){
    int ans = 0;
    while(x){
        x /= 5;
        ans += x;
    }
    return ans;
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    std::cout.tie(0);
    int N;
    std::cin >> N;
    int l = 0, r = 400000016;
    while(l+1<r){
        int mid = (l+r)/2;
        if(log5(mid)>=N) r = mid;
        else l = mid;
    }
    if(log5(r)==N) std::cout<<r<<std::endl;
    else std::cout<<-1<<std::endl;
    return 0;
}