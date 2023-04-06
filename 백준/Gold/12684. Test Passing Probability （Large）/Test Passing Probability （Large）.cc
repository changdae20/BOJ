#include <bits/stdc++.h>

int main(){
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios_base::sync_with_stdio(false);
    std::cout.setf(std::ios::fixed);
    #ifndef BOJ
    freopen("input.txt", "r", stdin);
    #endif
    
    int C;
    std::cin >> C;

    for(int i=1; i<=C; i++){
        int M, Q;
        std::cin >> M >> Q;

        std::vector<double> probs{1.0};

        double a,b,c,d;
        while(Q--){
            std::vector<double> new_probs;
            new_probs.reserve(probs.size() * 4);
            std::cin >> a >> b >> c >> d;
            
            for(auto& prob : probs){
                new_probs.push_back(prob * a);
                new_probs.push_back(prob * b);
                new_probs.push_back(prob * c);
                new_probs.push_back(prob * d);
            }

            std::sort(new_probs.begin(), new_probs.end(), std::greater<double>());
            new_probs.erase( std::next(new_probs.begin(), std::min(static_cast<int> (new_probs.size()), M)), new_probs.end());
            probs.swap(new_probs);
        }

        std::cout << "Case #" << i << ": " << std::setprecision(9) << std::accumulate(probs.begin(), probs.end(), 0.0) << '\n';
    }
    
    return 0;
}