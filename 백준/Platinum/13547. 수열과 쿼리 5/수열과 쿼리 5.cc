#include <bits/stdc++.h>

size_t current_l = 0;
size_t current_r = 0;

std::vector<int> arr;
std::vector<int> count(1000001, 0);
int ans = 0;

const int sqrt_n = 316;

class Query{
public:
    int l, r, id;
    Query(): l(0), r(0), id(0) {}
    Query(int l, int r, int id): l(l), r(r), id(id) {}
    bool operator < (const Query &q) const {
        if(r/sqrt_n != q.r/sqrt_n) return r < q.r;
        return l < q.l;
    }

    int run(){

        while(current_l < l){
            count[arr[current_l]]--;
            if(count[arr[current_l]] == 0) ans--;
            current_l++;
        }
        while(current_l > l){
            current_l--;
            if(count[arr[current_l]] == 0) ans++;
            count[arr[current_l]]++;
        }
        while(current_r < r){
            current_r++;
            if(count[arr[current_r]] == 0) ans++;
            count[arr[current_r]]++;
        }
        while(current_r > r){
            count[arr[current_r]]--;
            if(count[arr[current_r]] == 0) ans--;
            current_r--;
        }

        return ans;
    }
};

std::istream& operator>>(std::istream& in, Query& q){
    in >> q.l >> q.r;
    return in;
}

int main(int argc, char** argv){
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios_base::sync_with_stdio(false);

    #ifndef BOJ
    freopen(argv[1], "r", stdin);
    #endif

    int N;
    std::cin >> N;

    arr.resize(N+1);

    current_l = 1;
    current_r = N;

    for(int i = 1; i <= N; i++){
        std::cin >> arr[i];
        if(count[arr[i]]==0) ans++;
        count[arr[i]]++;
    }

    int Q;
    std::cin >> Q;

    std::vector<Query> queries(Q);
    for(int i = 0; i < Q; i++){
        std::cin >> queries[i];
        queries[i].id = i;
    }

    std::sort(queries.begin(), queries.end());

    std::vector<int> answer(Q);

    for(int i = 0; i < Q; i++){
        answer[queries[i].id] = queries[i].run();
    }

    for(int i = 0; i < Q; i++){
        std::cout << answer[i] << "\n";
    }

    return 0;
}