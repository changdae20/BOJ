#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

int N;

void update(std::vector<std::pair<long long,long long>>& tree, int cur_node, int start_of_this_node, int end_of_this_node, int update_idx, long long update_value) {
    if (start_of_this_node == end_of_this_node) {
        tree[cur_node] = std::pair(update_value, 0);
        return;
    }
    int mid = (start_of_this_node + end_of_this_node) / 2;
    if (update_idx <= mid) {
        update(tree, cur_node * 2, start_of_this_node, mid, update_idx, update_value);
    }
    else {
        update(tree, cur_node * 2 + 1, mid + 1, end_of_this_node, update_idx, update_value);
    }

    if(tree[cur_node * 2].first > tree[cur_node * 2 + 1].first){
        tree[cur_node] = std::pair(tree[cur_node * 2].first, std::max(tree[cur_node * 2].second, tree[cur_node * 2 + 1].first));
    }else{
        tree[cur_node] = std::pair(tree[cur_node * 2 + 1].first, std::max(tree[cur_node * 2 + 1].second, tree[cur_node * 2].first));
    }

    return;
}

auto get_pair(std::vector<std::pair<long long,long long>>& tree, int cur_node, int start_of_this_node, int end_of_this_node, int start_of_query, int end_of_query) {
    if ( start_of_this_node == start_of_query && end_of_this_node == end_of_query ) {
        return tree[cur_node];
    }

    int mid = (start_of_this_node + end_of_this_node) / 2;

    if ( end_of_query <= mid ) { // 왼쪽으로 내려감
        return get_pair(tree, 2 * cur_node , start_of_this_node, mid, start_of_query, end_of_query);
    }
    else if( mid < start_of_query ) { // 오른쪽으로 내려감
        return get_pair(tree, 2 * cur_node + 1, mid + 1, end_of_this_node, start_of_query, end_of_query);
    }else {
        auto left = get_pair(tree, 2 * cur_node, start_of_this_node, mid, start_of_query, mid);
        auto right = get_pair(tree, 2 * cur_node + 1, mid+1, end_of_this_node, mid+1, end_of_query);
        if(left.first > right.first){
            return std::pair(left.first, std::max(left.second, right.first));
        }else{
            return std::pair(right.first, std::max(right.second, left.first));
        }
    }
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> N;
    std::vector<std::pair<long long,long long>> tree(4 * N + 400, std::pair(0,0));

    for (int i = 1; i <= N; i++) {
        long long num;
        std::cin >> num;
        update(tree, 1, 1, N, i, num);
    }

    int Q;
    std::cin >> Q;

    while(Q--){
        int a,b,c;
        std::cin >> a >> b >> c;
        switch(a){
            case 1:
                update(tree,1,1,N,b,c);
                break;
            case 2:
                auto [d,e] = get_pair(tree,1,1,N,b,c);
                std::cout << d+e << "\n";
                break;
        }
    }
    return 0;
}