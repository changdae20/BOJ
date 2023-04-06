#include <bits/stdc++.h>

size_t current_l = 0;
size_t current_r = 0;

std::vector<int> arr(100005, 0);
std::vector<int> count(100005, 0);
std::vector<int> count_count(100005, 0);
int ans = 0;

const int sqrt_n = 316;

void add(int i) {
    if (count[i]) count_count[count[i]]--;
    count[i]++;
    count_count[count[i]]++;
    ans = std::max<>(ans, count[i]);
}

void remove(int i) {
    count_count[count[i]]--;
    if (count[i] == ans && count_count[count[i]] == 0) ans--;
    count[i]--;
    count_count[count[i]]++;
}

class Query {
public:
    int l, r, id;
    Query() : l(0), r(0), id(0) {}
    Query(int l, int r, int id) : l(l), r(r), id(id) {}
    bool operator < (const Query& q) const {
        if (r / sqrt_n != q.r / sqrt_n) return r < q.r;
        return l < q.l;
    }

    int run() {
        for (int i = current_l; i < l; i++) remove(arr[i]);
        for (int i = current_l - 1; i >= l; i--) add(arr[i]);
        current_l = l;
        for (int i = current_r; i > r; i--) remove(arr[i]);
        for (int i = current_r + 1; i <= r; i++) add(arr[i]);
        current_r = r;
        return ans;
    }
};

int main(int argc, char** argv) {
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios_base::sync_with_stdio(false);
#ifndef BOJ
    auto f = freopen(argv[1], "r", stdin);
#endif

    int N;
    std::cin >> N;
    for(int i=0; i<N; ++i){
        std::cin >> arr[i];
    }

    int Q;
    std::cin >> Q;
    std::vector<Query> queries(Q);
    std::vector<int> answers(Q);
    for(int i=0; i<Q; ++i){
        int start, end;
        std::cin >> start >> end;
        queries[i].l = start-1;
        queries[i].r = end-1;
        queries[i].id = i;
    }

    std::sort(queries.begin(), queries.end());

    current_l = 0;
    current_r = 0;

    add(arr[0]);

    for(int i=0; i<Q; ++i){
        answers[queries[i].id] = queries[i].run();
    }

    for(auto& a : answers){
        std::cout << a << '\n';
    }

    return 0;
}