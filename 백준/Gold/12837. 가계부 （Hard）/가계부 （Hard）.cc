#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"

void update(std::vector<long long> &tree, int cur_node, int start, int end, int update_index, int update_value){
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

long long get_value(std::vector<long long> &tree, int cur_node, int start, int end, int start_of_sum, int end_of_sum){
    if(start==start_of_sum && end==end_of_sum){
        return tree[cur_node];
    }else{
        int mid = (start + end) / 2;
        if(end_of_sum <= mid){
            return get_value(tree, cur_node*2, start, mid, start_of_sum,end_of_sum);
        }else if(mid+1<=start_of_sum){
            return get_value(tree,cur_node*2+1, mid + 1, end, start_of_sum,end_of_sum);
        }else{
            return get_value(tree, cur_node*2, start, mid, start_of_sum, mid) + get_value(tree,cur_node*2+1, mid + 1, end, mid + 1,end_of_sum);
        }
    }


}
int main(void){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, K ;

    std::cin >> N >> K;
    std::vector<long long> tree(4*N);
    for(int i = 0; i < K; i++){
        int mode, p, q;
        std::cin >> mode >> p >> q;
        if(mode==1){
            update(tree, 1,1,N,p,q);    
        }else if(mode==2){
            std::cout<<get_value(tree,1,1,N,p,q)<<endl;
        }
    }

    return 0;
}