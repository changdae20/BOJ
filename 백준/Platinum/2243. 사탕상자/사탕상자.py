import sys
N = int(sys.stdin.readline())

tree = [0] * 4000000

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

def get_candy(cur_node, start_of_this_node, end_of_this_node, nth):
    if start_of_this_node==end_of_this_node:
        update(1,1,1000000,start_of_this_node,-1)
        return start_of_this_node
    mid = (start_of_this_node + end_of_this_node) // 2
    if nth <= tree[2*cur_node]:
        return get_candy(2*cur_node, start_of_this_node, mid, nth)
    else:
        return get_candy(2*cur_node + 1, mid + 1, end_of_this_node, nth - tree[2*cur_node])

for _ in range(N):
    query = sys.stdin.readline().split()

    if query[0]=="2":
        update(1,1,1000000,int(query[1]), int(query[2]))
    elif query[0]=="1":
        print(get_candy(1,1,1000000,int(query[1])))
