import sys

N, M= map(int,sys.stdin.readline().split())

tree = [[1000000000,0] for _ in range(4*N)]

def get_value(cur_node, start_of_this_node, end_of_this_node, index):
    if start_of_this_node==end_of_this_node:
        return tree[cur_node]
    mid = (start_of_this_node + end_of_this_node) // 2
    if index <= mid : return get_value(2*cur_node, start_of_this_node, mid, index)
    else: return get_value(2*cur_node + 1, mid+1, end_of_this_node , index)

def update(cur_node, start_of_this_node, end_of_this_node, update_idx, update_value):
    if start_of_this_node == end_of_this_node:
        tree[cur_node] = [update_value, update_value]
        return
    mid = (start_of_this_node + end_of_this_node) // 2
    if update_idx <= mid :
        update(cur_node*2, start_of_this_node, mid, update_idx, update_value)
        tree[cur_node] = [min(tree[cur_node][0], tree[cur_node*2][0]), max(tree[cur_node][1], tree[cur_node*2][1])]
    else:
        update(cur_node*2+1, mid+1, end_of_this_node, update_idx, update_value)
        tree[cur_node] = [min(tree[cur_node][0], tree[cur_node*2 + 1][0]), max(tree[cur_node][1], tree[cur_node*2 + 1][1])]
    
    return

def get_minmax(cur_node, start_of_this_node, end_of_this_node, start_of_sum, end_of_sum):
    if start_of_this_node==start_of_sum and end_of_this_node==end_of_sum : return tree[cur_node]
    mid = (start_of_this_node + end_of_this_node) // 2
    if end_of_sum <= mid:
        return get_minmax(2*cur_node, start_of_this_node, mid, start_of_sum, end_of_sum)
    elif start_of_sum > mid:
        return get_minmax(2*cur_node + 1, mid + 1, end_of_this_node, start_of_sum, end_of_sum)
    else:
        left_minmax = get_minmax(2*cur_node, start_of_this_node, mid, start_of_sum, mid)
        right_minmax = get_minmax(2*cur_node + 1, mid + 1, end_of_this_node, mid+1, end_of_sum)
        return  [min(left_minmax[0],right_minmax[0]), max(left_minmax[1],right_minmax[1])]

for i in range(1,N+1):
    update(1,1,N,i,int(sys.stdin.readline()))

for _ in range(M):
    first, second = map(int,sys.stdin.readline().split())
    print(" ".join([str(x) for x in get_minmax(1,1,N,first,second)]))
        