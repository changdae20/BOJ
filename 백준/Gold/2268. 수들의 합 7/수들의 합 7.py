import sys
N, K= map(int,sys.stdin.readline().split())

tree = [0] * 4*N

def get_value(cur_node, start_of_this_node, end_of_this_node, index):
    if start_of_this_node==end_of_this_node:
        return tree[cur_node]
    mid = (start_of_this_node + end_of_this_node) // 2
    if index <= mid : return get_value(2*cur_node, start_of_this_node, mid, index)
    else: return get_value(2*cur_node + 1, mid+1, end_of_this_node , index)

def update(cur_node, start_of_this_node, end_of_this_node, update_idx, update_value):
    tree[cur_node] += update_value
    if start_of_this_node == end_of_this_node: return
    mid = (start_of_this_node + end_of_this_node) // 2
    if update_idx <= mid : update(cur_node*2, start_of_this_node, mid, update_idx, update_value)
    else: update(cur_node*2+1, mid+1, end_of_this_node, update_idx, update_value)
    return
def get_sum(cur_node, start_of_this_node, end_of_this_node, start_of_sum, end_of_sum):
    if start_of_this_node==start_of_sum and end_of_this_node==end_of_sum : return tree[cur_node]
    mid = (start_of_this_node + end_of_this_node) // 2
    if end_of_sum <= mid:
        return get_sum(2*cur_node, start_of_this_node, mid, start_of_sum, end_of_sum)
    elif start_of_sum > mid:
        return get_sum(2*cur_node + 1, mid + 1, end_of_this_node, start_of_sum, end_of_sum)
    else:
        return get_sum(2*cur_node, start_of_this_node, mid, start_of_sum, mid) + get_sum(2*cur_node + 1, mid + 1, end_of_this_node, mid+1, end_of_sum)

for _ in range(K):
    mode, first, second = map(int,sys.stdin.readline().split())

    if mode==1:
        orig = get_value(1,1,N,first)
        if orig!=second: update(1,1,N,first, second-orig)
    elif mode==0:
        if second>=first:
            print(get_sum(1,1,N,first,second))
        else:
            print(get_sum(1,1,N,second,first))
