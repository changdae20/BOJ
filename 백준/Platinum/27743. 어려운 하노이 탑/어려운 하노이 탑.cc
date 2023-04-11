#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using Mat = std::vector<std::vector<long long>>;
constexpr long long MOD = 1e9+7;

Mat mat_mul(Mat& mat1, Mat& mat2){
    Mat ans{{{0,0,0}},{{0,0,0}},{{0,0,0}}};
    for(int i=0; i<3;++i)
        for(int j=0; j<3;++j)
            for(int k=0; k<3;++k)
                ans[i][j] = (ans[i][j] + mat1[i][k]*mat2[k][j])%MOD;

    return ans;
}

Mat mat_pow(Mat mat, long long exp){
    Mat ans = {{{1,0,0}},{{0,1,0}},{{0,0,1}}};
    while(exp){
        if(exp&1L) ans = mat_mul(ans,mat);
        exp >>= 1L;
        mat = mat_mul(mat,mat);
    }
    return ans;
}

int main(int argc, char* argv[]) {
    #ifndef BOJ
    freopen(argv[1], "r", stdin);
    #endif
    fastio;
	
	long long N,M;
    std::cin >> N >> M;
    Mat m{{{2,0,1}},{{1,0,0}},{{0,0,1}}};

    m = mat_pow(m, N-1);

    long long tmp1 = (((m[1][0]+m[1][2])%MOD) * (M%MOD))%MOD;
    long long tmp2 = (M-1)%MOD;

    if(M==1) std::cout << (2*tmp1 + 1)%MOD << std::endl;
    else std::cout << (4*tmp1 + 2*tmp2 + 1)%MOD << std::endl;

    return 0;
}