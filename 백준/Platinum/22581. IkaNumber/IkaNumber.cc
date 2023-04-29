#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
using ull=unsigned long long;
constexpr ull MOD = 1e9+7;

ull pibonacci(ull n){
    auto matmul = [](const auto& a,const auto& b){
        auto ans = std::vector<std::vector<ull>> (2, std::vector<ull>(2));
        for(int i=0;i<2;++i)
            for(int j=0;j<2;++j)
                for(int k=0;k<2;++k)
                    ans[i][j] = (ans[i][j] + a[i][k]*b[k][j])%MOD;
        return ans;
    };

    std::vector<std::vector<ull>> base {{1,1},{1,0}};
    std::vector<std::vector<ull>> ans {{1,0},{0,1}};
    while(n){
        if(n&1uLL) ans = matmul(ans,base);
        n >>= 1uLL;
        base = matmul(base,base);
    }
    return ans[1][0];
}

template <typename predicate>
ull binary_search(ull s, ull e, predicate p){ // p(s)=false, p(e)=true이며 마지막으로 false가 되는 지점을 반환
    while(s+1<e){
        ull mid = (s+e)/2uLL;
        if(p(mid)) e = mid;
        else s = mid;
    }
    return s;
}

ull ans(ull N){
    if(N==1uLL) return 1uLL;
    ull m = binary_search(0, 1e9+1, [N](auto& a){return (a*a+1)>N;});
    if(m*m + m + 1 <= N){
        N -= (m*m + m + 1);
        m = 2*m+2;
    }else{
        N -= (m*m + 1);
        m = 2*m + 1;
    }
    ull first,second;
    if(m&1){
        first = m-2*N;
        second = 2+2*N;
    }else if(m&2){
        if(N <= (m-2)/4){
            first = m-2*N;
            second = 2+2*N;
        }else{
            N -= (m+2)/4;
            first = (m-4*N)/2;
            second = (m+4+4*N)/2;
        }
    }else{
        if(N <= (m-4)/4){
            first = m-2*N;
            second = 2+2*N;
        }else{
            N -= m/4;
            first = (m+2-4*N)/2;
            second = (m+2+4*N)/2;
        }
    }
    return (pibonacci(first)*pibonacci(second))%MOD;
}

int main(int argc, char* argv[]) {
    #ifndef BOJ
    freopen(argv[1], "r", stdin);
    #endif
    fastio;
	
    ull N;
    std::cin >> N;
    std::cout << ans(N) << std::endl;
    return 0;
}