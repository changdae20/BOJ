#include <bits/stdc++.h>

long double count_less_than(std::vector<int> &cumulative, int threshold){
    long double count = 0.0L;

    for(int start = 1; start <cumulative.size(); ++start){
        if(cumulative[start] - cumulative[start-1] >= threshold) continue;
        if(cumulative.back() - cumulative[start-1] < threshold){ // 끝까지 더해도 threshold가 안되면 무조건 괜찮으므로 1.0을 더함
            count += 1.0L;
            continue;
        }

        // 이 이후는 start는 threshold이하이나, 끝까지 더하면 넘게되므로 이분탐색으로 찾으면 됨.
        int l = start;
        int r = cumulative.size() - 1; // N

        while(l+1 < r){
            int mid = (l+r) / 2;
            if(cumulative[mid] - cumulative[start-1] < threshold){
                l = mid;
            }else{
                r = mid;
            }
        }

        // 여기 오면 l은 안전, r은 아님
        count += static_cast<long double> (l - start + 1) / (cumulative.size() - start);
    }

    return count / (cumulative.size()-1);
}

long double count_more_than(std::vector<int> &cumulative, int threshold){
    long double count = 0.0L;

    for(int start = 1; start <cumulative.size(); ++start){
        if(cumulative.back() - cumulative[start-1] <= threshold) continue; // start부터 끝까지 더했는데도 threshold를 넘는 경우가 없음.
        if(cumulative[start] - cumulative[start-1] > threshold){ // start만 해도 이미 threshold를 넘는다면 이 경우는 endpoint를 어떻게 잡든 넘으므로 1.0을 더함
            count += 1.0L;
            continue;
        }
        
        // 이 이후는 start는 threshold이하이나, 끝까지 더하면 넘게되므로 이분탐색으로 찾으면 됨.
        int l = start;
        int r = cumulative.size() - 1; // N

        while(l+1 < r){
            int mid = (l+r) / 2;
            if(cumulative[mid] - cumulative[start-1] <= threshold){ // start부터 mid까지의 합이 아직 threshold 이하
                l = mid;
            }else{
                r = mid;
            }
        }

        // 여기 오면 l은 threshold 이하, r은 초과
        count += static_cast<long double> (cumulative.size() - r) / (cumulative.size() - start);
    }

    return count / (cumulative.size()-1);
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
    std::cout << std::fixed;
    std::cout.precision(12);

    int T;
    std::cin >> T;
    
    while(T--){
        int N;
        std::cin >> N;
        std::vector<int> v(N);
        std::vector<int> cumulative(N+1, 0);
        char c;
        for(int i=1; i<=N; ++i){
            std::cin >> c;
            v[i-1] = c - 'A';
            cumulative[i] = cumulative[i-1] + v[i-1];
        } 

        int L, U;
        std::cin >> L >> U;

        long double less = count_less_than(cumulative, L);
        long double more = count_more_than(cumulative, U);
        long double safe = 1.0L - less - more;

        std::cout << safe << ' ' << less << ' ' << more << '\n';
    }
	return 0;
}