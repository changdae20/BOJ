#include <bits/stdc++.h>

int main(){
    #ifndef BOJ
    freopen("input.txt", "r",stdin);
    #endif

    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    int N;
    std::cin >> N;

    int sum;
    for(sum=1; (sum)*(sum+1)<2*N;) ++sum;
    int min = N - sum*(sum-1)/2;
    ++sum;
    std::cout << ((sum&1) ? min : (sum-min)) << "/" << ((sum&1) ? (sum-min) : min);

    return 0;
}