N = int(input())
cost = []
for i in range(0,N):
    cost.append(list(map(int,input().split())))

data = [[0 for _ in range(3)] for _ in range(N)]
data[0][0] = cost[0][0]
data[0][1] = cost[0][1]
data[0][2] = cost[0][2]

for i in range(1,len(data)):
    data[i][0] = min(data[i-1][1],data[i-1][2]) + cost[i][0]
    data[i][1] = min(data[i-1][0],data[i-1][2]) + cost[i][1]
    data[i][2] = min(data[i-1][0],data[i-1][1]) + cost[i][2]
    
print(min(data[N-1][0],data[N-1][1],data[N-1][2]))