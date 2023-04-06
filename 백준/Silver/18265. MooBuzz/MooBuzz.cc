#include <iostream>

unsigned long long Moo(unsigned long long x){
    return x - x/3uLL - x/5ull + x/15ull;

}
int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    std::cout.tie(0);
    
    int n;
    std::cin >> n;
    unsigned long long l = 0;
    unsigned long long r = 15000000000uLL;

    while(l+1<r){
        unsigned long long mid = (l+r)/2;
        if( Moo(mid) >= n ) r = mid;
        else l = mid;
    }
    while(l%3 || l%5) l--;
    std::cout << r << std::endl;
    return 0;
}