#include <bits/stdc++.h>
 
std::vector<int> ratings;
std::vector<std::vector<double>> win_rate;

void prob(int start, int end, int round){ // 각 사람이 round에서 이길 확률을 계산
    if(start==end){ // terminal state
        win_rate[start][round] = 1.0;
        return;
    }

    int mid = (start+end)/2;

    prob(start, mid, round+1); // 왼쪽 트리
    prob(mid+1, end, round+1); // 오른쪽 트리

    // 왼쪽 트리 합침
    for( int left = start; left <= mid; left++ ){
        double ans = 0.0;
        for( int right = mid+1; right <= end; right++ ){
            ans += win_rate[left][round+1] * win_rate[right][round+1] * (ratings[left] / static_cast<double>(ratings[left] + ratings[right]));
        }
        win_rate[left][round] = ans;
    }

    // 오른쪽 트리 합침
    for( int right = mid+1; right <= end; right++ ){
        double ans = 0.0;
        for( int left = start; left <= mid; left++ ){
            ans += win_rate[left][round+1] * win_rate[right][round+1] * (ratings[right] / static_cast<double>(ratings[left] + ratings[right]));
        }
        win_rate[right][round] = ans;
    }

    return;
}

int main(){
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios_base::sync_with_stdio(false);
    std::cout.setf(std::ios::fixed);
    #ifndef BOJ
    freopen("input.txt", "r", stdin);
    #endif
    
    int N;
    std::cin >> N;

    int pow2 = 1;
    while( pow2 < N ) pow2 *= 2;

    ratings.resize(pow2+1);
    std::cin >> ratings[1];

    std::vector<double> others_rating(N-1);
    
    for(int i=0; i<N-1; i++){
        std::cin >> others_rating[i];
    }

    std::sort(others_rating.begin(), others_rating.end());

    int idx = 2;
    if(pow2 != N) ratings[idx++] = 0;

    for(int i=1; i<N; i++){
        if((i+1)*2 + (N-i-1) <= pow2){
            ratings[idx++] = others_rating[i-1];
            ratings[idx++] = others_rating[i-1];
        }
        else{
            ratings[idx++] = others_rating[i-1];
        }
    }

    win_rate = std::vector<std::vector<double>>(pow2+1, std::vector<double>(15, -1.0));
    prob(1, pow2, 0); // start, end, round
    std::cout << std::setprecision(12) << win_rate[1][0] << std::endl;
    return 0;
}