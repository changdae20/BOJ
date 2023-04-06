import sys

N = int(sys.stdin.readline())

ans = [[[int(j==(1<<i) if i!=0 and k==0 else 0) for j in range(1<<10)] for i in range(10)] for k in range(N)]
for i in range(1,N):
    for j in range(1024):
        ans[i][0][j | (1<<0)] += ans[i-1][1][j]
        ans[i][1][j | (1<<1)] += ans[i-1][0][j] + ans[i-1][2][j]
        ans[i][2][j | (1<<2)] += ans[i-1][1][j] + ans[i-1][3][j]
        ans[i][3][j | (1<<3)] += ans[i-1][2][j] + ans[i-1][4][j]
        ans[i][4][j | (1<<4)] += ans[i-1][3][j] + ans[i-1][5][j]
        ans[i][5][j | (1<<5)] += ans[i-1][4][j] + ans[i-1][6][j]
        ans[i][6][j | (1<<6)] += ans[i-1][5][j] + ans[i-1][7][j]
        ans[i][7][j | (1<<7)] += ans[i-1][6][j] + ans[i-1][8][j]
        ans[i][8][j | (1<<8)] += ans[i-1][7][j] + ans[i-1][9][j]
        ans[i][9][j | (1<<9)] += ans[i-1][8][j]

val = (ans[-1][0][1023] + ans[-1][1][1023] + ans[-1][2][1023] + ans[-1][3][1023] + ans[-1][4][1023] + ans[-1][5][1023] + ans[-1][6][1023] + ans[-1][7][1023] + ans[-1][8][1023] + ans[-1][9][1023]) % (10**9)
print(val)