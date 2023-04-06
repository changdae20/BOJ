#include <bits/stdc++.h>

std::array<int, 1000001> dp;

int get(int N){
	if(N==1) return 0;
	
	if(N%6==0){
		if(dp[N]) return dp[N];
		int first = get(N/3);
		int second = get(N/2);
		int third = get(N-1);
		dp[N] = std::min(std::min(first, second), third) + 1;
		return dp[N];
	}else if(N%3==0){
		if(dp[N]) return dp[N];
		int first = get(N/3);
		int third = get(N-1);
		dp[N] = std::min(first, third) + 1;
		return dp[N];
	}else if(N%2==0){
		if(dp[N]) return dp[N];
		int second = get(N/2);
		int third = get(N-1);
		dp[N] = std::min(second, third) + 1;
		return dp[N];
	}else{
		if(dp[N]) return dp[N];
		dp[N] = get(N-1) + 1;
		return dp[N];
	}
}
int main() {
    int N;
	std::cin >> N;
	std::cout << get(N) << std::endl;
	
	return 0;
}