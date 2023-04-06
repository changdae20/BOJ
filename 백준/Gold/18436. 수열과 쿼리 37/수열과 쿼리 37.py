import sys
N = int(sys.stdin.readline())

tree = [[0,0]] * 4*N

def get_value(cur_node, start_of_this_node, end_of_this_node, index):
    if start_of_this_node==end_of_this_node:
        return tree[cur_node]
    mid = (start_of_this_node + end_of_this_node) // 2
    if index <= mid : return get_value(2*cur_node, start_of_this_node, mid, index)
    else: return get_value(2*cur_node + 1, mid+1, end_of_this_node , index)

def update(cur_node, start_of_this_node, end_of_this_node, update_idx, update_value):
    if start_of_this_node == end_of_this_node:
        tree[cur_node] = [update_value%2, 1-update_value%2]
        return
    mid = (start_of_this_node + end_of_this_node) // 2
    if update_idx <= mid : update(cur_node*2, start_of_this_node, mid, update_idx, update_value)
    else: update(cur_node*2+1, mid+1, end_of_this_node, update_idx, update_value)
    tree[cur_node] = [tree[cur_node*2][0]+tree[cur_node*2+1][0], tree[cur_node*2][1]+tree[cur_node*2+1][1]]

def get_even_odd(cur_node, start_of_this_node, end_of_this_node, start_of_sum, end_of_sum):
    if start_of_this_node==start_of_sum and end_of_this_node==end_of_sum : return tree[cur_node]
    mid = (start_of_this_node + end_of_this_node) // 2
    if end_of_sum <= mid:
        return get_even_odd(2*cur_node, start_of_this_node, mid, start_of_sum, end_of_sum)
    elif start_of_sum > mid:
        return get_even_odd(2*cur_node + 1, mid + 1, end_of_this_node, start_of_sum, end_of_sum)
    else:
        left_result = get_even_odd(2*cur_node, start_of_this_node, mid, start_of_sum, mid)
        right_result = get_even_odd(2*cur_node + 1, mid + 1, end_of_this_node, mid+1, end_of_sum)
        return [left_result[0]+right_result[0], left_result[1]+right_result[1]]

init = list(map(int,sys.stdin.readline().split()))
for i in range(1,N+1):
    update(1,1,N,i,init[i-1])
    
K = int(sys.stdin.readline())
for _ in range(K):
    mode, first, second = map(int,sys.stdin.readline().split())
    if mode == 1:  
        update(1,1,N,first, second)
    elif mode==2:
        print(get_even_odd(1,1,N,first,second)[1])
    elif mode==3:
        print(get_even_odd(1,1,N,first,second)[0])