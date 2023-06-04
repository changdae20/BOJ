import sys
N = int(sys.stdin.readline())
arr = list(map(int,sys.stdin.readline().rstrip().split()))
arr.append(arr[0])

ans = 0
for i in range(len(arr)-1):
    if arr[i]>=arr[i+1]:
        ans +=1
print(ans)