#include <numeric>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>

using uLL = unsigned long long;

uLL mod_pow(uLL A, uLL B, uLL M) {
	if (B == 0) return 1LL;
	uLL ans = 1uLL;
    while(B>0){
        if (B&1) {
            ans = ans*A % M;
        }
        B >>= 1;
        A = A*A % M;
    }
    return ans;
}

uLL phi(uLL N) {
	uLL ans = N;
	for (uLL p = 2; p <= std::pow(N, 0.5f); p++) {
		if (N%p == 0) {
			ans -= ans / p;
			while (N%p == 0) N /= p;
		}
		if (N < p) break;
	}
	if (N > 1) ans -= ans / N;
	return ans;
}

uLL ans(uLL N, uLL M){
    if(M==1uLL){
        return 0uLL;
    }else if(N==2uLL){
        return 2 % M;
    }else if(N==3uLL){
        return 9 % M;
    }else if(N==4uLL){
        return (1<<18)%M;
    }else if(N==5uLL){
        return mod_pow(5,(1<<18)%phi(M),M);
    }else{
        uLL p = phi(M);
        return mod_pow(N,p+ans(N-1,p),M);
    }
}


int main(void){
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	uLL N,M;
	std::cin >> N >> M;
    std::cout << ans(N,M) << '\n';

    return 0;
}