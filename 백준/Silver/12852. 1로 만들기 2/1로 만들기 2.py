import sys

N = int(sys.stdin.readline())

ans = [[-1, 999999]] * (N+1) # array of [parent, depth]

ans[1] = [-1,0]
for i in range(1,N+1):
    if 3*i<=N and ans[3*i][1]>ans[i][1]+1:
        ans[3*i] = [i, ans[i][1]+1]
    if 2*i<=N and ans[2*i][1]>ans[i][1]+1:
        ans[2*i] = [i, ans[i][1]+1]
    if i+1<=N and ans[i+1][1]>ans[i][1]+1:
        ans[i+1] = [i, ans[i][1]+1]

way = []
current = N
while current>0:
    way.append(str(current))
    current = ans[current][0]
print(len(way)-1)
print(" ".join(way))