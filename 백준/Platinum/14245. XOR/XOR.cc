#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

unsigned int get(std::vector<unsigned int>& tree, std::vector<unsigned int>& lazy, int start_idx, int end_idx, int current_idx, int query_start, int query_end){
    if(lazy[current_idx]){
        unsigned int _lazy = lazy[current_idx];
        lazy[current_idx] = 0u;
        tree[current_idx] ^= (((end_idx - start_idx + 1) % 2 == 1) ? _lazy : 0u);
        if(2*current_idx < lazy.size()) lazy[2*current_idx] ^= _lazy;
        if(2*current_idx+1 < lazy.size()) lazy[2*current_idx + 1] ^= _lazy;
    }

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
        return left ^ right;
    }
}

void update(std::vector<unsigned int>& tree, std::vector<unsigned int>& lazy, int start_idx, int end_idx, int current_idx, int query_start, int query_end, unsigned int value){
    if(start_idx == query_start && end_idx == query_end){
        lazy[current_idx] ^= value;
        return;
    }
    int mid = (start_idx + end_idx)/2;
    if(query_end <= mid){
        update(tree, lazy, start_idx, mid, 2*current_idx, query_start, query_end, value);
    }else if(mid+1 <=query_start){
        update(tree, lazy, mid+1, end_idx, 2*current_idx + 1, query_start, query_end, value);
    }else{
        update(tree, lazy, start_idx, mid, 2*current_idx, query_start, mid, value);
        update(tree, lazy, mid+1, end_idx, 2*current_idx+1, mid+1, query_end, value);
    }
    auto left = get(tree, lazy, start_idx, mid, 2*current_idx, start_idx, mid);
    auto right = get(tree, lazy, mid+1, end_idx, 2*current_idx + 1, mid+1, end_idx);

    tree[current_idx] = left^right;
    return;
}
int main(int argc, char* argv[]) {
    #ifndef BOJ
    freopen(argv[1], "r", stdin);
    #endif
    fastio;
	
	int N;
    std::cin >> N;

    std::vector<unsigned int> tree(4*N);
    std::vector<unsigned int> lazy(4*N);

    unsigned int x;
    for(int i=1; i<=N; ++i){
        std::cin >> x;
        update(tree, lazy, 1, N, 1, i, i, x);
    }
    int Q;
    std::cin >> Q;
    unsigned int q, l, r, v;
    while(Q--){
        std::cin >> q;
        switch (q) {
        case 1u:
            std::cin >> l >> r >> v;
            update(tree, lazy, 1, N, 1, l+1, r+1, v);
            break;
        case 2u:
            std::cin >> l;
            std::cout << get(tree, lazy, 1, N, 1, l+1, l+1) << '\n';
            break;
        }
    }
    return 0;
}