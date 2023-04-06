import sys

MOD = 1000000007

N, M, K= map(int,sys.stdin.readline().split())

tree = [1] * 4*N

def get_value(cur_node, start_of_this_node, end_of_this_node, index):
    if start_of_this_node==end_of_this_node:
        return tree[cur_node]
    mid = (start_of_this_node + end_of_this_node) // 2
    if index <= mid : return get_value(2*cur_node, start_of_this_node, mid, index)
    else: return get_value(2*cur_node + 1, mid+1, end_of_this_node , index)

def update(cur_node, start_of_this_node, end_of_this_node, update_idx, update_value):
    if start_of_this_node == end_of_this_node:
        tree[cur_node] = update_value%MOD
        return
    mid = (start_of_this_node + end_of_this_node) // 2
    if update_idx <= mid :
        update(cur_node*2, start_of_this_node, mid, update_idx, update_value)
    else:
        update(cur_node*2+1, mid+1, end_of_this_node, update_idx, update_value)
    tree[cur_node] = ((tree[2*cur_node]%MOD) * (tree[2*cur_node + 1]%MOD))%MOD
    return 

def get_product(cur_node, start_of_this_node, end_of_this_node, start_of_sum, end_of_sum):
    if start_of_this_node==start_of_sum and end_of_this_node==end_of_sum : return tree[cur_node]
    mid = (start_of_this_node + end_of_this_node) // 2
    if end_of_sum <= mid:
        return get_product(2*cur_node, start_of_this_node, mid, start_of_sum, end_of_sum)
    elif start_of_sum > mid:
        return get_product(2*cur_node + 1, mid + 1, end_of_this_node, start_of_sum, end_of_sum)
    else:
        return ((get_product(2*cur_node, start_of_this_node, mid, start_of_sum, mid)%MOD) * (get_product(2*cur_node + 1, mid + 1, end_of_this_node, mid+1, end_of_sum)%MOD))%MOD

for i in range(1,N+1):
    update(1,1,N,i,int(sys.stdin.readline()))

for _ in range(M+K):
    mode, first, second = map(int,sys.stdin.readline().split())

    if mode==1:
        update(1,1,N,first, second)
    elif mode==2:
        print(get_product(1,1,N,first,second))