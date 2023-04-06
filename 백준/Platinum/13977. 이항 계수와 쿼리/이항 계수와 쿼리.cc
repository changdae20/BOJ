#include <iostream>
#include <vector>
#define endl "\n"
#define MOD 1000000007
std::vector<int> fac;

void append_fac(int num){
   while(fac.size()<num+1){
       fac.push_back(static_cast<int> ((static_cast<long long>(fac[fac.size()-1]) * static_cast<long long>(fac.size())) % MOD));
   } 
   return;
}

int pow_mod(long long a,int b){
    long long temp = a%MOD;
    int answer = 1;
    while(b>0){
        if(b%2){
            answer = (static_cast<long long> (answer) * temp) % MOD;
        }
        temp = (temp * temp)%MOD;
        b /= 2;
    }
    return answer;
}

int main(void){
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); 
    fac.push_back(1);
    
    int M;
    std::cin>>M;

    for(int i=0;i<M;i++){
        int N,K;
        std::cin>>N>>K;
        append_fac(N);
        std::cout<<(static_cast<long long> (fac[N]) * static_cast<long long> (pow_mod(static_cast<long long> (fac[K])* static_cast<long long> (fac[N-K]),MOD-2)))%MOD<<endl;
    }
    
    return 0;
}