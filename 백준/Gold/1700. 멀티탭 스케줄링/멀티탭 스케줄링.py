import sys
N, K = map(int, sys.stdin.readline().split())
arr = []
count = 0

nums = list(map(int,sys.stdin.readline().split()))

for idx, num in enumerate(nums):
    #print("curr arr : ",arr)
    #print("have to insert num",num)
    if num in arr: continue
    
    if(len(arr)<N): arr.append(num)
    else:
        where = [K+1] * len(arr)
        for idx_cand, cand in enumerate(nums[idx+1::][::-1]):
            for idx_arr, arr_num in enumerate(arr):
                if arr_num == cand : where[idx_arr] = K-idx_cand
                #print(where[0])
        #print(where)
        what_to_delete = max([(min_val, min_idx) for min_idx, min_val in enumerate(where)])[1]
        #print("delete",arr[what_to_delete])
        del arr[what_to_delete]
        arr.append(num)
        count += 1

print(count)