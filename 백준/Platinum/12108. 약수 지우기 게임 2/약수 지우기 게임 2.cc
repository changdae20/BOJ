#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

constexpr std::array<unsigned int,30> get_alliance(){
    constexpr auto helper = [](){
        std::array<unsigned int,30> arr = {0, };
        for(int i=1;i<30;++i){
            for(int j=1; j<=i; ++j){
                if(i%j==0){ // j는 i의 약수
                    arr[i] |= (1<<j);
                }
            }
        }
        return arr;
    };

    return helper();
};

constexpr std::array<unsigned int,30> alliance = get_alliance();

void erase(unsigned int& N, unsigned int M){
    N = (N^M)&N;
    return;
}

std::map<unsigned int, unsigned int> cache;

unsigned int grundy(unsigned int N){
    if(N==0u) return 0u;
    
    int count_one = __builtin_popcount(N);
    if(count_one==1) return 1u;
    else if(cache.find(N) != cache.end()) return cache[N];

    unsigned int tmp = N;
    unsigned int tmp2 = N;

    unsigned int s = 0u;
    while(count_one--){ // 남아있는 수들에 대해
        tmp &= tmp-1u; // 마지막 1제거
        unsigned int next = __builtin_ffs(tmp2 ^ tmp)-1; // 그 다음 작은 숫자

        unsigned int copied_N = N;
        erase(copied_N, alliance[next]);
        s |= (1<<grundy(copied_N));

        tmp2 = tmp;
    }

    unsigned int ans = 0u;
    while(s & (1<<ans)) ++ans;

    cache[N] = ans;
    return ans;
}
int main(int argc, char* argv[]) {
    #ifndef BOJ
    freopen(argv[1], "r", stdin);
    #endif
    fastio;
	
	int N;
    std::vector<unsigned int> arr;
    unsigned int x;
    unsigned int total = 0u;

    std::cin >> N;
    for(int i=0; i<N; ++i){
        std::cin >> x;
        arr.push_back(x);
        total |= (1<<x);
    }

    for(int i=0; i<N; ++i){ // 맨 처음 i번째 수를 지움
        unsigned int total_copied = total;
        erase(total_copied, alliance[arr[i]]);
        std::cout << '(' << arr[i] << ") ";
        
        std::vector<unsigned int> ans;
        for(int j=0; j<N; ++j){ // j번째 수를 지웠을 때 이기는지 검사
            if(!(total_copied&(1<<arr[j]))) continue;
            unsigned int total_copied_copied = total_copied;
            erase(total_copied_copied, alliance[arr[j]]);
            if(!grundy(total_copied_copied)) ans.push_back(arr[j]);
        }

        if(ans.size()){
            for(auto& el : ans) std::cout << el << ' ';
            std::cout << std::endl;
        }else{
            std::cout << "A\n";
        }
    }

    return 0;
}