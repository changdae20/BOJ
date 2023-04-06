#include <bits/stdc++.h>

int find(std::vector<int> &tree, int cur_node, int start_of_this_node, int end_of_this_node, int value){
    if(start_of_this_node == end_of_this_node){ // 누적보다 큰 값 찾는 경우 -1 리턴
        if(value==1) return start_of_this_node;
        else return -1;
    }

    int mid = (start_of_this_node + end_of_this_node) / 2;

    if (tree[2*cur_node] >= value) return find(tree, cur_node*2, start_of_this_node, mid, value);
    else return find(tree, cur_node*2+1, mid+1, end_of_this_node, value-tree[2*cur_node]);
}

void update(std::vector<int> &tree, int cur_node, int start_of_this_node, int end_of_this_node, int update_idx, int update_value){
    if(start_of_this_node == end_of_this_node){
        tree[cur_node] = update_value;
        return;
    }
    int mid = (start_of_this_node + end_of_this_node) / 2;
    if(update_idx <= mid){
        update(tree, cur_node*2, start_of_this_node, mid, update_idx, update_value);
    } 
    else{
        update(tree, cur_node*2+1, mid+1, end_of_this_node, update_idx, update_value);
    }
    tree[cur_node] = tree[cur_node*2] + tree[cur_node*2+1];
    return;
}

int get(std::vector<int> &tree, int cur_node, int start_of_this_node, int end_of_this_node, int start_idx, int end_idx){
    if(start_of_this_node == start_idx && end_of_this_node == end_idx){
        return tree[cur_node];
    }

    int mid = (start_of_this_node + end_of_this_node) / 2;

    if(end_idx <= mid) return get(tree, cur_node*2, start_of_this_node, mid, start_idx, end_idx);
    else if(start_idx >= mid+1) return get(tree, cur_node*2+1, mid+1, end_of_this_node, start_idx, end_idx);
    else return get(tree, cur_node*2, start_of_this_node, mid, start_idx, mid) + get(tree, cur_node*2+1, mid+1, end_of_this_node, mid+1, end_idx);
}


int main(void){
    #ifndef BOJ
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int N, K;
    std::cin >> N >> K;
    std::vector<int> tree(4*N);
    
    for(int i=1;i<=N;++i){
        update(tree,1,1,N,i,1);
    }
    int curr = 1;

    std::cout << '<';
    for(int i=1; i<N;++i){
        int goal_count = (K-1) % tree[1] + 1; // 전체 살아남아있는 사람이 tree[1]이므로 goal_count까지 찾는다
        int alive_till_end = get(tree,1,1,N,curr,N);
        if(alive_till_end < goal_count){ // curr~N까지 살아있는 사람이 K명이 안됨
            goal_count -= alive_till_end;
            curr = 1;
        }

        if(curr!=1){
            goal_count += (tree[1] - alive_till_end);
        }

        int next = find(tree,1,1,N,goal_count);

        curr = next;
        update(tree,1,1,N,curr,0);
        std::cout << curr << ", ";
    }
    std::cout << find(tree,1,1,N,1) << ">\n";
    return 0;
}