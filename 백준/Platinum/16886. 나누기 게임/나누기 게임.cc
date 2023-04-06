#include <bits/stdc++.h>

int N = 0;
int Moong_Tang_E = INT_MAX;
std::vector<int> sum_of_interval(50001);
std::vector<int> g_n(100001, -1); // -1이면 아직 구하지 않은 그런디 넘버.

unsigned long long grundy(unsigned long long i){
    std::vector<int> mex;
    for(int s = 1; s<=i/2; s++){
        auto it = std::lower_bound(sum_of_interval.begin(), sum_of_interval.end(), i+sum_of_interval[s-1]);
        if(*it == (i + sum_of_interval[s-1])){
            int e = std::distance(sum_of_interval.begin(), it);
            int ans = 0;
            for(int k = s; k<=e; k++){
                if(g_n[k]==-1){
                    g_n[k] = grundy(k);
                }
                ans ^= g_n[k];
            }
            mex.push_back(ans);
        }
    }
    std::sort(mex.begin(), mex.end());
    mex.erase(std::unique(mex.begin(), mex.end()), mex.end());
    if(i==N){ // 재귀 끝에 입력값에 대한 그런디 넘버를 구하는 경우, ans값을 만드는 뭉탱이의 최소값으로 설정
        for(int s = 1; s<=i/2; s++){
            auto it = std::lower_bound(sum_of_interval.begin(), sum_of_interval.end(), i+sum_of_interval[s-1]);
            if(*it == (i + sum_of_interval[s-1])){
                int e = std::distance(sum_of_interval.begin(), it);
                int ans = 0;
                for(int k = s; k<=e; k++){
                    ans ^= g_n[k];
                }
                if(ans==0) Moong_Tang_E = std::min<>(Moong_Tang_E, e-s+1);
            }
        }
    }
    return std::distance(mex.begin(), std::find_if(mex.begin(), mex.end(), [t=0](auto &el) mutable {return el != t++;}));
}

int main(int argc, char** argv){
    #ifndef BOJ
    freopen(argv[1], "r", stdin);
    #endif


    // Initialize
    for(int i=1; i<50001;++i){
        sum_of_interval[i] = sum_of_interval[i-1] + i;
    }

    g_n[0] = 0;
    g_n[1] = 0;

    std::cin >> N;

    auto g = grundy(N);

    if(g){
        std::cout << Moong_Tang_E << std::endl;
    }else{
        std::cout << -1 << std::endl;
    }

    return 0;
}