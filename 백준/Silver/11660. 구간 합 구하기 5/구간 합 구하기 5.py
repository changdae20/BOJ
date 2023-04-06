import sys

N,M = map(int,sys.stdin.readline().split())
mat = [list(map(int,sys.stdin.readline().split())) for _ in range(N)]

DP = [[0 for _ in range(N+1)] for _ in range(N+1)]

for i in range(1,N+1):
    for j in range(1,N+1):
        DP[i][j] = mat[i-1][j-1] + DP[i-1][j] + DP[i][j-1] - DP[i-1][j-1]
        
for i in range(M):
    x1,y1,x2,y2 = map(int,sys.stdin.readline().split())
    print(DP[x2][y2]-DP[x1-1][y2]-DP[x2][y1-1]+DP[x1-1][y1-1])