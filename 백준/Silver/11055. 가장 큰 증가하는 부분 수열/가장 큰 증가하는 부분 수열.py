N = int(input())
num = [0] + list(map(int,input().split()))

ans = [0 for _ in range(len(num))]

for i in range(0,len(num)):
    for j in range(i):
        if ans[j]+num[i]>ans[i] and num[i]>num[j] : ans[i] = ans[j]+num[i]
     
print(max(ans))