N = int(input())
num = []
for i in range(N):
    num.append(list(map(int,input().split())))
    
for j in range(N-2,-1,-1):
    for k in range(j+1):
        num[j][k] += max(num[j+1][k],num[j+1][k+1])
     
print(num[0][0])