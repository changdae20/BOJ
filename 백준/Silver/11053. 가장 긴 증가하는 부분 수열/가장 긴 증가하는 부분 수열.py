N = int(input())
num = list(map(int,input().split()))

ans = [0 for _ in range(len(num))]

for i in range(0,len(num)):
    for j in range(i):
        if ans[j]+1>ans[i] and num[i]>num[j] : ans[i] = ans[j]+1
     
print(max(ans)+1)