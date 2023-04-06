#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"

void append(std::vector<int> &tree, int cur_node, int start_of_this_node, int end_of_this_node, int update_idx, int update_value){
    if(start_of_this_node == end_of_this_node){
        tree[cur_node] = update_value;
        return;
    }
    int mid = (start_of_this_node + end_of_this_node) / 2;
    if(update_idx <= mid){
        append(tree, cur_node*2, start_of_this_node, mid, update_idx, update_value);
    } 
    else{
        append(tree, cur_node*2+1, mid+1, end_of_this_node, update_idx, update_value);
    }
    tree[cur_node] = tree[cur_node*2] + tree[cur_node*2 + 1];
    return;
}

int update(std::vector<int> &tree, int cur_node, int start_of_this_node, int end_of_this_node, int value){
    if(start_of_this_node == end_of_this_node){
        int temp = cur_node;
        while(temp>=1){
            tree[temp]--;
            temp>>=1;
        }
        return start_of_this_node;
    }
    int mid = (start_of_this_node + end_of_this_node) / 2;
    if(value < tree[cur_node*2]){
        return update(tree, cur_node*2, start_of_this_node, mid, value);
    } 
    else{
        return update(tree, cur_node*2+1, mid+1, end_of_this_node, value-tree[cur_node*2]);
    }
}


int main(void){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int N;
    std::cin >> N;
    std::vector<int> tree(4*N);
    std::vector<int> arr(N);
    for(int i=1;i<=N;i++){
        append(tree,1,1,N,i,1);
    }
    for(int i=1;i<=N;i++){
        int num;
        std::cin >> num;
        arr[update(tree,1,1,N,num)-1] = i;
    }
    for(const auto &i : arr){
        std::cout << i << " ";
    }
    return 0;
}