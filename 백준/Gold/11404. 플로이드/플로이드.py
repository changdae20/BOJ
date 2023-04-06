N = int(input())
M = int(input())
MAX = 99999999999
w = [[MAX for _ in range(N)] for _ in range(N)]
ans = [[MAX for _ in range(N)] for _ in range(N)]
for i in range(N):
    w[i][i]=0
    ans[i][i]=0

for _ in range(M):
    start, end, cost = map(int,input().split())
    w[start-1][end-1] = min(cost,w[start-1][end-1])
    ans[start-1][end-1] = w[start-1][end-1]

for k in range(N): # i번째 weight 갱신
    for i in range(N): 
        for j in range(N): # j to k Cost를 갱신
            ans[i][j] = min(ans[i][j],ans[i][k]+ans[k][j])

for i in range(N):
    for j in range(N):
        if ans[i][j]==MAX:print(0,end=" ")
        else: print(ans[i][j],end=" ")
    print("")