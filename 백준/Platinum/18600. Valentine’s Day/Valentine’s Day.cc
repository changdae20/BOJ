#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

int main(int argc, char* argv[]) {
    #ifndef BOJ
    freopen(argv[1], "r", stdin);
    #endif
    fastio;
	
	int T;
    std::cin >> T;
    std::cout << std::fixed;
    std::cout.precision(12);
    while(T--){
        int N;
        std::cin >> N;
        std::vector<double> v(N);
        for(auto& el : v) std::cin >> el;

        if(N==1) std::cout << v[0] << '\n';
        else{
            std::sort(v.begin(), v.end());

            if(v.back()>=0.5) std::cout << v.back() << '\n';
            else{
                double p0 = 1 - v.back();
                double p1 = v.back();

                for(int i = v.size()-2; i>=0; --i){
                    if(p0 <= p1) break;

                    p1 = p0 * v[i] + p1 * (1-v[i]);
                    p0 *= (1 - v[i]);
                }
                std::cout << p1 << '\n';
            }
        }
        
    }
    return 0;
}