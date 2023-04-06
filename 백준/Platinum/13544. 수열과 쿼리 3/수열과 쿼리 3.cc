#include <iostream>
#include <algorithm>
#include <vector>

int get_upperbound(std::vector<std::vector<int>> &tree, int cur_node, int start_of_this_node, int end_of_this_node, int start_of_interval, int end_of_interval, int K){
    if(start_of_this_node==start_of_interval && end_of_this_node==end_of_interval){
        return tree[cur_node].size() - (std::upper_bound(tree[cur_node].begin(),tree[cur_node].end(),K) - tree[cur_node].begin());
    }
    int mid = (start_of_this_node + end_of_this_node) / 2;
    if(end_of_interval <= mid){
        return get_upperbound(tree, 2*cur_node, start_of_this_node, mid, start_of_interval, end_of_interval, K);
    }else if(start_of_interval > mid){
        return get_upperbound(tree, 2*cur_node + 1, mid + 1, end_of_this_node, start_of_interval, end_of_interval,K);
    }else{
        return get_upperbound(tree,2*cur_node, start_of_this_node, mid, start_of_interval, mid,K) + get_upperbound(tree,2*cur_node + 1, mid + 1, end_of_this_node, mid+1, end_of_interval,K);
    }
}

void update(std::vector<std::vector<int>> &tree, int cur_node, int start_of_this_node, int end_of_this_node, int update_idx, int update_value){
    if(start_of_this_node == end_of_this_node){
        tree[cur_node].push_back(update_value);
        return;
    }
    int mid = (start_of_this_node + end_of_this_node) / 2;
    if(update_idx <= mid){
        update(tree, cur_node*2, start_of_this_node, mid, update_idx, update_value);
    } 
    else{
        update(tree, cur_node*2+1, mid+1, end_of_this_node, update_idx, update_value);
    }
    tree[cur_node].push_back(update_value);
    return;
}


int main(void){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int N;
    std::cin >> N;
    std::vector<std::vector<int>> tree(4*N);
    
    for(int i=1;i<=N;i++){
        int num;
        std::cin >> num;
        update(tree,1,1,N,i,num);
    }
    for(auto &v : tree){
        sort(v.begin(),v.end());
    }

    int K;
    std::cin >> K;
    int ans = 0;
    int first, second, threshold;
    for(int i=0;i<K;i++){
        
        std::cin >> first >> second >> threshold;
        first ^= ans;
        second ^= ans;
        threshold ^= ans;
        ans = get_upperbound(tree,1,1,N,first,second,threshold);
        std::cout << ans << "\n";
    }
    return 0;
}