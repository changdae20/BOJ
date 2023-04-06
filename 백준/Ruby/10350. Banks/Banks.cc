#include <bits/stdc++.h>

unsigned long long solve(std::vector<long long> &arr, int N){
    long long ans = 0;
    long long total = arr[N];
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=N; ++j){
            if(j < i){ // 1~j, i~N
                long long sub_total = arr[j] + arr[N] - arr[i-1];
                if(sub_total < 0)
                    ans += std::abs(std::floor( sub_total / static_cast<double> (total)));
            }else{ // i~j
                long long sub_total = arr[j] - arr[i-1];
                if(sub_total < 0)
                    ans += std::abs(std::floor( sub_total / static_cast<double> (total)));
            }
        }
    }
    return ans;
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
    
    int N;
    std::cin >> N;
    std::vector<long long> arr(N+1);
    for(int i=1; i<=N; ++i){
        std::cin >> arr[i];
        arr[i] += arr[i-1]; 
    }

    std::cout << solve(arr, N) << std::endl;
	return 0;
}