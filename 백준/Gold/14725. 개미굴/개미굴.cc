#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio( false );std::cin.tie( NULL );std::cout.tie( NULL );

void print_pretty(std::vector<std::vector<std::string>>& arr, int start = 0, int end = -2, int depth = 0){
    if(end == -2) end = arr.size()-1;
    if(start==end){ // Base case
        if(depth >= arr[start].size()) return;
    }
    // [start, end] 까지 depth번째 단어가 다른 지점을 찾는다
    int partial_start = start;
    int partial_end = start;
    while(partial_end <= end){
        while(partial_end <= end && arr[partial_start][depth] == arr[partial_end][depth]){
            ++partial_end;
            if(partial_end > end) break;
        }
        std::cout << std::string(2*depth, '-') << arr[partial_start][depth] << std::endl;
        print_pretty(arr, partial_start, partial_end-1, depth+1);
        partial_start = partial_end;
    }
    return;
}
int main( int argc, char *argv[] ) {
#ifndef BOJ
    freopen( argv[ 1 ], "r", stdin );
#endif
    fastio;

    int N;
    std::cin >> N;
    std::vector<std::vector<std::string>> arr(N);

    for(auto& row : arr){
        int M;
        std::cin >> M;
        row.reserve(M);
        std::string s;
        while(M--){
            std::cin >> s;
            row.push_back(s);
        }
    }
    
    std::sort(arr.begin(), arr.end(), [](auto &a, auto &b){
        std::string s1 = std::accumulate(a.begin(), a.end(), std::string(), [](auto sum, auto& s){
            return sum + s + std::string(15 - s.size(), ' ');
        });

        std::string s2 = std::accumulate(b.begin(), b.end(), std::string(), [](auto sum, auto& s){
            return sum + s + std::string(15 - s.size(), ' ');
        });

        return std::strcmp(s1.c_str(),s2.c_str())<0;
    });

    print_pretty(arr);
    return 0;
}