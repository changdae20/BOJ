#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"

void update(std::vector<int> &tree, int cur_node, int start, int end, int update_index, int update_value){
    if(start==end){
        tree[cur_node] += update_value;
        return;
    }else{
        int mid = (start+end) / 2;
        if(update_index <= mid){
            update(tree, cur_node*2, start, mid, update_index, update_value);
        }else if(mid+1<=update_index){
            update(tree, cur_node*2+1, mid+1, end, update_index, update_value);
        }
        tree[cur_node] += update_value;
        return;
    }
}

int get_value(std::vector<int> &tree, int cur_node, int start, int end, int nth){
    if(start==end){
        return start;
    }else{
        int mid = (start + end) / 2;
        if(tree[cur_node*2]>=nth){
            return get_value(tree, cur_node*2, start, mid, nth);
        }else{
            return get_value(tree,cur_node*2+1, mid + 1, end, nth - tree[cur_node*2]);
        }
    }


}
int main(void){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    unsigned long long count = 0;

    int N, K ;

    std::cin >> N >> K;
    std::vector<int> tree(4*65537);
    std::vector<int> inputs;
    for(int i = 0; i < K-1; i++){
        int tmp;
        std::cin >> tmp;
        inputs.push_back(tmp);
        update(tree, 1,0,65536,tmp,1);
    }

    // update(tree,1,1,65536,5,1);
    // std::cout << get_value(tree,1,1,65535,(K+1)/2) << endl;
    // update(tree,1,1,65536,inputs[0],-1);
    // inputs.erase(inputs.begin());
    for(int i = 0; i< N-K+1; i++){
        int tmp;
        std::cin >> tmp;
        inputs.push_back(tmp);
        update(tree,1,0,65536,tmp,1);
        count += get_value(tree,1,0,65536,(K+1)/2);
        update(tree,1,0,65536,inputs[0],-1);
        inputs.erase(inputs.begin());
    }
    std::cout << count;

    return 0;
}