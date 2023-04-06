import sys
N = int(sys.stdin.readline())

tree = [[] for _ in range(4*N)]

def upper_bound(nums, target):
    left, right = 0, len(nums)
    while left < right:
        mid = left + (right - left) // 2
        if nums[mid] <= target:
            left = mid + 1
        else:
            right = mid 
    return right

def update(cur_node, start_of_this_node, end_of_this_node, update_idx, update_value):
    global tree
    if start_of_this_node == end_of_this_node:
        tree[cur_node].append(update_value)
        return
    mid = (start_of_this_node + end_of_this_node) // 2
    if update_idx <= mid : update(cur_node*2, start_of_this_node, mid, update_idx, update_value)
    else: update(cur_node*2+1, mid+1, end_of_this_node, update_idx, update_value)
    tree[cur_node].append(update_value)
    return
    

def get_upperbound(cur_node, start_of_this_node, end_of_this_node, start_of_sum, end_of_sum, K):
    if start_of_this_node==start_of_sum and end_of_this_node==end_of_sum: return len(tree[cur_node]) - upper_bound(tree[cur_node],K)
    mid = (start_of_this_node + end_of_this_node) // 2
    if end_of_sum <= mid:
        return get_upperbound(2*cur_node, start_of_this_node, mid, start_of_sum, end_of_sum,K)
    elif start_of_sum > mid:
        return get_upperbound(2*cur_node + 1, mid + 1, end_of_this_node, start_of_sum, end_of_sum,K)
    else:
        return get_upperbound(2*cur_node, start_of_this_node, mid, start_of_sum, mid,K) + get_upperbound(2*cur_node + 1, mid + 1, end_of_this_node, mid+1, end_of_sum,K)

init = list(map(int,sys.stdin.readline().split()))
for i in range(1,N+1):
    update(1,1,N,i,init[i-1])
for vec in tree:
    vec.sort()

K = int(sys.stdin.readline())

for _ in range(K):
    first, second, number = map(int,sys.stdin.readline().split())
    print(get_upperbound(1, 1, N, first, second, number))