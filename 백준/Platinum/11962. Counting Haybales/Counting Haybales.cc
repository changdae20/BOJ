#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

std::pair<long long, long long> get(std::vector<std::pair<long long, long long>>& tree, std::vector<long long>& lazy, int start_idx, int end_idx, int current_idx, int query_start, int query_end){
    if(lazy[current_idx]){
        if(end_idx != start_idx){
            lazy[2*current_idx] += lazy[current_idx];
            lazy[2*current_idx+1] += lazy[current_idx];
        }
        tree[current_idx].first += lazy[current_idx] * (end_idx - start_idx + 1);
        tree[current_idx].second += lazy[current_idx];
        lazy[current_idx] = 0;
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
        return std::pair(left.first + right.first, std::min<>(left.second, right.second));
    }
}

void update(std::vector<std::pair<long long, long long>>& tree, std::vector<long long>& lazy, int start_idx, int end_idx, int current_idx, int query_start, int query_end, long long value){
    // if(lazy[current_idx]){
    //     if(end_idx != start_idx){
    //         lazy[2*current_idx] = lazy[current_idx];
    //         lazy[2*current_idx+1] = lazy[current_idx];
    //     }
    //     tree[current_idx] = (1 << (lazy[current_idx]-1));
    //     lazy[current_idx] = 0;
    // }
    
    if(start_idx == query_start && end_idx == query_end){
        lazy[current_idx] += value;
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

    tree[current_idx] = std::pair(left.first + right.first, std::min<>(left.second, right.second));
    return;
}

int main(int argc, char* argv[]) {
    #ifndef BOJ
    freopen(argv[1], "r", stdin);
    #endif
    fastio;
	
	int N,Q;
    std::cin >> N >> Q;
    std::vector<std::pair<long long, long long>> tree(4 * N);
    std::vector<long long> lazy(4 * N, 0);
    long long x;
    for(int i=1; i<=N; ++i){
        std::cin >> x;
        update(tree, lazy, 1, N, 1, i, i, x);
    }
    char q;    
    int l,r,v;
    while(Q--){
        std::cin >> q;
        switch(q){
            case 'P':
                std::cin >> l >> r >> v;
                update(tree,lazy,1,N,1,l,r,v);
                break;
            case 'M':
                std::cin >> l >> r;
                std::cout << get(tree,lazy,1,N,1,l,r).second << '\n';
                break;
            case 'S':
                std::cin >> l >> r;
                std::cout << get(tree,lazy,1,N,1,l,r).first << '\n';
                break;
        }
    }
    return 0;
}