#include <bits/stdc++.h>

int main(int argc, char* argv[]){
#ifndef BOJ
    freopen(argv[1], "r", stdin);
#endif
    std::cin.tie(NULL);
    std::ios::sync_with_stdio( false );
    std::cout.tie(NULL);

    int N, M;
    std::cin >> N >> M;

    std::vector<int> StreetLamps(M+2, 0);
    for(int i=1; i <= M; ++i) std::cin >> StreetLamps[i];
    StreetLamps[0] = -100000; // 이분탐색용 가짜 가로등 하나 추가 : -100000에 추가하면 정답에 영향X
    StreetLamps[M+1] = 200000; // 이분탐색용 가짜 가로등 하나 추가 : 200000에 추가하면 정답에 영향X

    int ans = 0;

    for(int i=0; i<N; ++i){ // [0,1] 부터 [N-1,N]까지 모두 필요한 가로등 높이의 max를 구할거임
        int l = 0;
        int r = M+1;
        while(l+1 < r){ // 이분탐색으로 가장 가까운 왼쪽과 오른쪽 가로등을 구해서
            int mid = (l+r) / 2;
            if(StreetLamps[mid] > i) r = mid;
            else l = mid;
        }
        ans = std::max<>(ans, std::min<>(std::abs(i + 1 - StreetLamps[l]), std::abs(i - StreetLamps[r]))); // 필요한 가로등 = (구간의 왼쪽~ 오른쪽 가로등), (구간의 오른쪽~왼쪽가로등)의 최소
    }

    std::cout << ans << '\n';

    return 0;
}