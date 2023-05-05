#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

constexpr long long MOD = 1e9+7;

long long get(std::vector<long long>& tree, std::vector<std::pair<long long, long long>>& lazy, int start_idx, int end_idx, int current_idx, int query_start, int query_end){
    auto& [curr_coeff, curr_bias] = lazy[current_idx];
    tree[current_idx] = (curr_coeff * tree[current_idx]) % MOD;
    tree[current_idx] += (curr_bias * (end_idx - start_idx + 1));
    tree[current_idx] %= MOD;

    if(start_idx != end_idx){
        auto& [left_coeff, left_bias] = lazy[2*current_idx];
        left_coeff = (left_coeff * curr_coeff) % MOD;
        left_bias = (left_bias * curr_coeff + curr_bias) % MOD;

        auto& [right_coeff, right_bias] = lazy[2*current_idx+1];
        right_coeff = (right_coeff * curr_coeff) % MOD;
        right_bias = (right_bias * curr_coeff + curr_bias) % MOD;
    }
    lazy[current_idx] = std::pair(1,0);

    if(start_idx == query_start && end_idx == query_end){
        return tree[current_idx];
    }

    int mid = (start_idx + end_idx)/2;
    if(query_end <= mid){
        return get(tree, lazy, start_idx, mid, 2*current_idx, query_start, query_end);
    }else if(mid+1 <=query_start){
        return get(tree, lazy, mid+1, end_idx, 2*current_idx + 1, query_start, query_end);
    }else{
        auto left = get(tree, lazy, start_idx, mid, 2*current_idx, query_start, mid);
        auto right = get(tree, lazy, mid+1, end_idx, 2*current_idx+1, mid+1, query_end);
        return (left + right)%MOD;
    }
}

void update(std::vector<long long>& tree, std::vector<std::pair<long long, long long>>& lazy, int start_idx, int end_idx, int current_idx, int query_start, int query_end, int op, long long value){
    if(start_idx == query_start && end_idx == query_end){
        auto& [curr_coeff, curr_bias] = lazy[current_idx];
        switch(op){
            case 1:
                curr_bias += value;
                curr_bias %= MOD;
                break;
            case 2:
                curr_coeff *= value;
                curr_coeff %= MOD;
                curr_bias *= value;
                curr_bias %= MOD;
                break;
            case 3:
                curr_coeff = 0;
                curr_bias = (value % MOD);
                break;
        }
        return;
    }else{
        auto& [curr_coeff, curr_bias] = lazy[current_idx];
        tree[current_idx] = (curr_coeff * tree[current_idx]) % MOD;
        tree[current_idx] += (curr_bias * (end_idx - start_idx + 1));
        tree[current_idx] %= MOD;

        if(start_idx != end_idx){
            auto& [left_coeff, left_bias] = lazy[2*current_idx];
            left_coeff = (left_coeff * curr_coeff) % MOD;
            left_bias = (left_bias * curr_coeff + curr_bias) % MOD;

            auto& [right_coeff, right_bias] = lazy[2*current_idx+1];
            right_coeff = (right_coeff * curr_coeff) % MOD;
            right_bias = (right_bias * curr_coeff + curr_bias) % MOD;
        }
        lazy[current_idx] = std::pair(1,0);
    }
    int mid = (start_idx + end_idx)/2;
    if(query_end <= mid){
        update(tree, lazy, start_idx, mid, 2*current_idx, query_start, query_end, op, value);
    }else if(mid+1 <=query_start){
        update(tree, lazy, mid+1, end_idx, 2*current_idx + 1, query_start, query_end, op, value);
    }else{
        update(tree, lazy, start_idx, mid, 2*current_idx, query_start, mid, op, value);
        update(tree, lazy, mid+1, end_idx, 2*current_idx+1, mid+1, query_end, op, value);
    }
    auto left = get(tree, lazy, start_idx, mid, 2*current_idx, start_idx, mid);
    auto right = get(tree, lazy, mid+1, end_idx, 2*current_idx + 1, mid+1, end_idx);

    tree[current_idx] = (left+right) % MOD;
    return;
}
int main(int argc, char* argv[]) {
    #ifndef BOJ
    freopen(argv[1], "r", stdin);
    #endif
    fastio;
	
	int N,Q;
    std::cin >> N;

    std::vector<long long> tree(4*N);
    std::vector<std::pair<long long, long long>> lazy(4*N, std::pair(1,0));
    long long x;
    for(int i=1; i<=N; ++i){
        std::cin >> x;
        update(tree, lazy, 1, N, 1, i, i, 1, x);
    }
    std::cin >> Q;
    long long q, l, r, v;
    while(Q--){
        std::cin >> q;
        switch (q) {
        case 1:
        case 2:
        case 3:
            std::cin >> l >> r >> v;
            update(tree, lazy, 1, N, 1, l, r, q, v);
            break;
        case 4:
            std::cin >> l >> r;
            std::cout << get(tree, lazy, 1, N, 1, l, r) << '\n';
            break;
        }
    }
    return 0;
}