#include <iostream>

unsigned long long MOD = 1000000007;

unsigned long long mod_pow(unsigned long long A, unsigned long long B, unsigned long long M = MOD) {
	if (B == 0) return 1LL;
	unsigned long long ans = 1uLL;
	A %= M;
	while (B > 0) {
		if (B & 1) {
			ans = (ans * A) % M;
		}
		B >>= 1;
		A = (A * A) % M;
	}
	return ans;
}


unsigned long long div_2 = mod_pow(2, MOD - 2);

void ans(unsigned long long N, unsigned long long M) {
    unsigned long long alpha = N;
    unsigned long long beta = 1uLL;

    unsigned long long x = 1uLL;
    unsigned long long y = 0uLL;
    unsigned long long temp, temp2;
    unsigned long long N2_1 = (N*N-1)%MOD;


    temp = x;
    x = ((x*alpha)%MOD + (((beta*y)%MOD) * N2_1)%MOD)%MOD;
    y = ((temp*beta)%MOD + (y*alpha)%MOD)%MOD;
    temp = alpha;
    temp2 = beta;
    alpha = alpha*alpha % MOD;
    alpha = (alpha + ((beta*beta) % MOD * N2_1)%MOD ) % MOD;
    beta = (2*temp*temp2)%MOD;

    while(M>0){
        if (M & 1) {
            temp = x;
			x = ((x*alpha)%MOD + (((beta*y)%MOD) * N2_1)%MOD)%MOD;
            y = ((temp*beta)%MOD + (y*alpha)%MOD)%MOD;
		}
		M >>= 1;
        temp = alpha;
        temp2 = beta;
		alpha = alpha*alpha % MOD;
        alpha = (alpha + ((beta*beta) % MOD * N2_1)%MOD ) % MOD;
        beta = (2*temp*temp2)%MOD;
    }
    unsigned long long div_N = mod_pow(N, MOD - 2);
    y += 1;
    unsigned long long orange = (x * div_N)%MOD + 1;
    orange = orange&1 ? (orange * div_2)%MOD : orange/2;
    
    y = y&1 ? (y * div_2)%MOD : y/2;

    std::cout << y << ' ' << orange << '\n';
    return;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

    int Q;
    std::cin >> Q;

    while(Q--){
        unsigned long long N, M;
        std::cin >> N >> M;
        ans(N,M);
    }
	return 0;
}