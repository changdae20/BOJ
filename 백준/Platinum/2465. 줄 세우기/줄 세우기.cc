#include <iostream>
#include <algorithm>
#include <vector>

int N;

void update(std::vector<int>& tree, int cur_node, int start_of_this_node, int end_of_this_node, int update_idx, int update_value) {
    if (start_of_this_node == end_of_this_node) {
        tree[cur_node] = update_value;
        return;
    }
    int mid = (start_of_this_node + end_of_this_node) / 2;
    if (update_idx <= mid) {
        update(tree, cur_node * 2, start_of_this_node, mid, update_idx, update_value);
    }
    else {
        update(tree, cur_node * 2 + 1, mid + 1, end_of_this_node, update_idx, update_value);
    }
    tree[cur_node] = tree[cur_node * 2] + tree[cur_node * 2 + 1];
    return;
}

int get_num(std::vector<int>& tree, int cur_node, int start_of_this_node, int end_of_this_node, int K) {
    if (start_of_this_node == end_of_this_node) {
        update(tree,1,1,N,start_of_this_node,0);
        return start_of_this_node;
    }

    int mid = (start_of_this_node + end_of_this_node) / 2;

    if (tree[2*cur_node] >= K) {
        return get_num(tree, 2 * cur_node, start_of_this_node, mid, K);
    }
    else {
        return get_num(tree, 2 * cur_node + 1, mid + 1, end_of_this_node, K-tree[2*cur_node]);
    }
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> N;
    std::vector<int> tree(4 * N);
    std::vector<int> keys;

    for (int i = 1; i <= N; i++) {
        update(tree, 1, 1, N, i, 1);
        int key;
        std::cin >> key;
        keys.push_back(key);
    }
    std::sort(keys.begin(), keys.end());

    std::vector<int> indices;
    for(int i=0;i<N;i++){
        int idx;
        std::cin >> idx;
        indices.push_back(idx);
    }

    std::vector<int> ans;
    for(auto iter = indices.rbegin(); iter!=indices.rend(); ++iter){
        ans.push_back(get_num(tree,1,1,N,(*iter)+1));
    }

    for(auto iter = ans.rbegin(); iter!=ans.rend(); ++iter){
        std::cout << keys[(*iter)-1] << "\n";
    }


    return 0;
}