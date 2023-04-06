N, max_weight = map(int,input().split())
data = [[0 for _ in range(2)] for _ in range(N)]
for i in range(N):
    weight, value = map(int,input().split())
    data[i] = [weight,value]

DP = [[0 for _ in range(N+1)] for _ in range(max_weight+1)]

for i in range(1,N+1):
    for j in range(1,max_weight+1):
        if j>= data[i-1][0] : DP[j][i] = max(DP[j][i-1], DP[j-data[i-1][0]][i-1] + data[i-1][1])
        else: DP[j][i] = DP[j][i-1]
        
print(DP[-1][-1])