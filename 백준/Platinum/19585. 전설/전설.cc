#include <bits/stdc++.h>

const long long MOD = 998244353LL;
const std::vector<long long> primes = {7603LL};

std::map<long long, std::vector<long long>> p_pows;
std::map<long long, std::set<long long>> team_name_hash;
std::map<long long, std::set<long long>> color_hash;

void bake_pows(){
    for(const auto& p : primes){
        p_pows[p] = std::vector<long long>(2000);
        p_pows[p][0] = 1;
        for(int i=1; i<2000; ++i){
            p_pows[p][i] = (p_pows[p][i-1] * p) % MOD;
        }
    }
    return;
}

long long hash(std::string &s, long long p){
    return std::inner_product(s.begin(), s.end(), p_pows[p].begin(), 0LL, [](auto& a, auto b){return (a+b)%MOD;}, std::multiplies<>());
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    bake_pows();
    int C,N,Q;
    std::cin >> C >> N;
    while(C--){
        std::string s;
        std::cin >> s;
        for(const auto& p : primes){
            color_hash[p].insert(hash(s,p));
        }
    }
    while(N--){
        std::string s;
        std::cin >> s;
        std::reverse(s.begin(), s.end());
        for(const auto& p : primes){
            team_name_hash[p].insert(hash(s,p));
        }
    }

    std::cin >> Q;
    while(Q--){
        std::string s;
        std::cin >> s;

        int i = std::max(1, static_cast<int>(s.size()) - 1000); // 0<= <= 1000
        int e = std::min(1000, static_cast<int>(s.size())-1); // 2 <= 1000

        std::map<long long, std::pair<long long, long long>> hashes;
        bool end = false;
        for(const auto& p : primes){
            auto tmp2 = s.substr(0,i);
            auto l = hash(tmp2,p);
            std::string tmp = s.substr(i);
            std::reverse(tmp.begin(), tmp.end());
            auto r = hash(tmp, p);
            hashes[p] = std::pair(l,r);
        }
        while(i<=e){
            if(std::all_of(primes.begin(), primes.end(), [&end, &hashes](auto p){
                auto [l,r] = hashes[p];
                return color_hash[p].count(l) && team_name_hash[p].count(r);
            })){
                end = true;
                break;
            }else{
                for(const auto& p : primes){
                    auto& [l,r] = hashes[p];
                    l = (l + p_pows[p][i] * s[i]) % MOD;
                    r = (((r - p_pows[p][s.size() - 1ul - i] * s[i]) % MOD) + MOD) % MOD;
                }
                ++i;
            }
        }

        if(end){std::cout << "Yes\n";}
        else std::cout << "No\n";

    }
    return 0;
}