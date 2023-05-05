#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

unsigned int get(std::vector<unsigned int>& tree, std::vector<unsigned int>& lazy, int start_idx, int end_idx, int current_idx, int query_start, int query_end){
    if(lazy[current_idx]){
        if(end_idx != start_idx){
            lazy[2*current_idx] = lazy[current_idx];
            lazy[2*current_idx+1] = lazy[current_idx];
        }
        tree[current_idx] = (1 << (lazy[current_idx]-1));
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
        return (left | right);
    }
}

void update(std::vector<unsigned int>& tree, std::vector<unsigned int>& lazy, int start_idx, int end_idx, int current_idx, int query_start, int query_end, unsigned int value){
    if(lazy[current_idx]){
        if(end_idx != start_idx){
            lazy[2*current_idx] = lazy[current_idx];
            lazy[2*current_idx+1] = lazy[current_idx];
        }
        tree[current_idx] = (1 << (lazy[current_idx]-1));
        lazy[current_idx] = 0;
    }
    
    if(start_idx == query_start && end_idx == query_end){
        lazy[current_idx] = value;
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

    tree[current_idx] = (left | right);
    return;
}
int main(int argc, char* argv[]) {
    #ifndef BOJ
    freopen(argv[1], "r", stdin);
    #endif
    fastio;
	
	int N,T,Q;
    std::cin >> N >> T >> Q;
    assert(N<=100000);
    std::vector<unsigned int> tree(4 * N);
    std::vector<unsigned int> lazy(4 * N, 0);
    for(int i=1; i<=N; ++i){
        update(tree, lazy, 1, N, 1, i, i, 1u);
    }
    char q;    
    int l,r,v;
    while(Q--){
        std::cin >> q;
        switch(q){
            case 'C':
                std::cin >> l >> r >> v;
                if(l>r) std::swap(l,r);
                update(tree,lazy,1,N,1,l,r,v);
                break;
            case 'Q':
                std::cin >> l >> r;
                if(l>r) std::swap(l,r);
                auto ans = get(tree,lazy,1,N,1,l,r);
                std::cout << __builtin_popcount(ans) << '\n';
                break;
        }
    }
    return 0;
}