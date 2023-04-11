#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

std::vector<int> phi(1001);
std::map<std::tuple<int,int,int>,int> cache;

int phi_N(int N) {
	if (N == 1) return 0;
	if (N == 2) return 1;
	int ans = N;
	for (int p = 2; p*p <= N; p++) {
		if (N%p == 0) {
			ans -= ans / p;
			while (N%p == 0) N /= p;
		}
		if (N < p) break;
	}
	if (N > 1) ans -= ans / N;
	return ans;
}

int mod_pow(int n, int exp, int mod){
    int ans = 1;
    while(exp){
        if(exp&1) ans = (ans * n) % mod;
        exp >>= 1;
        n = (n * n) % mod;
    }
    return ans;
}

int ans(int a, int b, int c){
    if(c==1) return 0;
    else if(a==1) return 1;
    else if(b==0) return (a%c);
    else if(b==1) return mod_pow(a,a,c);
    else if(b==2) return mod_pow(mod_pow(a,a,c), mod_pow(a,a,phi[c]) + [a,phic=phi[c]](){
        int tmp = 1;
        for(int i=1; i<=a; i++){
            tmp *= a;
            if(tmp >= phic) return 1;
        }
        return 0;
    }() * phi[c], c);
    else if(auto it = cache.find(std::tuple(a,b,c)); it!=cache.end()) return it->second;

    int base = ans(a,b-1,c);
    int exp = ans(a,b-1,phi[c]);

    return cache[std::tuple(a,b,c)] = mod_pow(base, phi[c]+exp, c);
}

int main(int argc, char* argv[]) {
    #ifndef BOJ
    freopen(argv[1], "r", stdin);
    #endif
    fastio;
	
	for(int i=0; i<=1000; ++i) phi[i] = phi_N(i);
    int T,A,B,C;
    std::cin >> T;
    for(int t=1; t<=T; ++t){
        std::cin >> A >> B >> C;
        std::cout << "Case #" << t << ": " << ans(A,B,C) << '\n';
    }

    return 0;
}