#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

void update(std::vector<int> &tree, int cur_node, int start_of_this_node, int end_of_this_node, int update_idx, int update_value){
    if(start_of_this_node == end_of_this_node){
        tree[cur_node] = update_value;
        return;
    }

    int mid = (start_of_this_node + end_of_this_node) / 2;
    if(update_idx <= mid){
        update(tree, 2*cur_node, start_of_this_node, mid, update_idx, update_value);
    }else if(mid+1 <= update_idx){
        update(tree, 2*cur_node+1, mid+1, end_of_this_node, update_idx, update_value);
    }

    tree[cur_node] = tree[2*cur_node] + tree[2*cur_node+1];

    return;
}

int get(std::vector<int> &tree, int cur_node, int start_of_this_node, int end_of_this_node, int start, int end){
    if(start_of_this_node == start && end_of_this_node == end){
        return tree[cur_node];
    }

    int mid = (start_of_this_node + end_of_this_node)/2;

    if( end <= mid ){
        return get(tree, 2*cur_node, start_of_this_node, mid, start, end);
    }else if( mid+1 <= start ){
        return get(tree, 2*cur_node+1, mid+1, end_of_this_node, start, end);
    }else{
        return get(tree, 2*cur_node, start_of_this_node, mid, start, mid) + get(tree, 2*cur_node+1, mid+1, end_of_this_node, mid+1, end);
    }
}
int main(int argc, char* argv[]) {
    #ifndef BOJ
    freopen(argv[1], "r", stdin);
    #endif
    fastio;

    int T;
    std::cin >> T;
    
    while(T--){
        int N, M, total;
        std::cin >> N >> M; 
        total = N+M;
        std::vector<int> tree(4*total);
        std::vector<int> cache(N+1);

        for(int i = 1; i <= N; ++i){
            cache[i] = (N+1-i);
            update(tree, 1, 1, total, i, 1);
        }

        int num;
        for(int i = 1; i <= M; ++i){
            std::cin >> num;
            std::cout << get(tree, 1, 1, total, cache[num], total)-1 << (i!=M ? " " : "");
            update(tree, 1, 1, total, cache[num], 0);
            update(tree, 1, 1, total, N+i, 1);
            cache[num] = N+i;
        }

        std::cout << '\n';
    }
	return 0;
}