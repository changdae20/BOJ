import sys

N = int(sys.stdin.readline())

dp = [[1 for _ in range(10)] for _ in range(N)]

for i in range(N-2,-1,-1):
    for j in range(10):
        dp[i][j] = sum(dp[i+1][j:10]) % 10007

print(sum(dp[0])% 10007)