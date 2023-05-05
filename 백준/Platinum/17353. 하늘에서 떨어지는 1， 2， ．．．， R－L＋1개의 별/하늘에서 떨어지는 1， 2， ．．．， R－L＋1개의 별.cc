#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

long long get(std::vector<long long>& tree, std::vector<std::pair<long long, long long>>& lazy, int start_idx, int end_idx, int current_idx, int query_start, int query_end){
    if(lazy[current_idx].first || lazy[current_idx].second){
        tree[current_idx] += (lazy[current_idx].first * 2 + (end_idx - start_idx) * lazy[current_idx].second) * (end_idx - start_idx + 1) / 2;
        if(2*current_idx < lazy.size()){
            lazy[2*current_idx].first += lazy[current_idx].first;
            lazy[2*current_idx].second += lazy[current_idx].second;
        }
        int mid = (start_idx + end_idx) / 2;
        if(2*current_idx+1 < lazy.size()){
            lazy[2*current_idx + 1].first += lazy[current_idx].first + (mid - start_idx + 1) * lazy[current_idx].second;
            lazy[2*current_idx + 1].second += lazy[current_idx].second;
        }
        lazy[current_idx] = std::pair(0,0);
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
        return left + right;
    }
}

void update(std::vector<long long>& tree, std::vector<std::pair<long long,long long>>& lazy, int start_idx, int end_idx, int current_idx, int query_start, int query_end, long long value){
    if(start_idx == query_start && end_idx == query_end){
        lazy[current_idx].first += value;
        ++lazy[current_idx].second;
        return;
    }
    int mid = (start_idx + end_idx)/2;
    if(query_end <= mid){
        update(tree, lazy, start_idx, mid, 2*current_idx, query_start, query_end, value);
    }else if(mid+1 <=query_start){
        update(tree, lazy, mid+1, end_idx, 2*current_idx + 1, query_start, query_end, value);
    }else{
        update(tree, lazy, start_idx, mid, 2*current_idx, query_start, mid, value);
        update(tree, lazy, mid+1, end_idx, 2*current_idx+1, mid+1, query_end, value + (mid-query_start + 1));
    }
    auto left = get(tree, lazy, start_idx, mid, 2*current_idx, start_idx, mid);
    auto right = get(tree, lazy, mid+1, end_idx, 2*current_idx + 1, mid+1, end_idx);

    tree[current_idx] = left+right;
    return;
}
int main(int argc, char* argv[]) {
    #ifndef BOJ
    freopen(argv[1], "r", stdin);
    #endif
    fastio;
	
	int N,x;
    std::cin >> N;
    std::vector<long long> tree(4*N);
    std::vector<std::pair<long long,long long>> lazy(4*N);

    for(int i=1; i<=N; ++i){
        std::cin >> x;
        update(tree, lazy, 1, N, 1, i, i, x);
    }
    int Q;
    std::cin >> Q;
    long long q, l, r, v;
    while(Q--){
        std::cin >> q;
        switch (q) {
        case 1:
            std::cin >> l >> r;
            update(tree, lazy, 1, N, 1, l, r, 1);
            break;
        case 2:
            std::cin >> l;
            std::cout << get(tree, lazy, 1, N, 1, l, l) << '\n';
            break;
        }
    }
    return 0;
}