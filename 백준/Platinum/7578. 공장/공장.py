import sys

N = int(sys.stdin.readline())
arr1 = {}
text = list(map(int,sys.stdin.readline().split()))
for i in range(N):
    arr1[text[i]] = i
arr = []
text = list(map(int,sys.stdin.readline().split()))
for i in range(N):
    arr.append(arr1[text[i]])

def merge_sort(arr,start,end):
    if start==end: return 0
    mid = (start+end)//2
    left_value = merge_sort(arr,start,mid)
    right_value = merge_sort(arr,mid+1,end)
    l = start - start
    r = mid+1 - (mid+1)
    left_arr = list(arr[start:mid+1] + [9999999999])
    right_arr = list(arr[mid+1:end+1] + [9999999999])
    swap_count = 0
    index = start
    while l<=mid-start or r<=end-mid-1:
        if left_arr[l] <= right_arr[r]:
            arr[index] = left_arr[l]
            l += 1
        else:
            arr[index] = right_arr[r]
            swap_count += (r + mid+1 - index)
            r += 1
        index += 1
    return left_value + right_value + swap_count

ret = merge_sort(arr,0,len(arr)-1)
print(ret)