import sys
N, M = map(int,sys.stdin.readline().split())
ans = {}
for _ in range(N):
    s = sys.stdin.readline().strip()
    if s not in ans.keys():
        ans[s] = 1
    else:
        ans[s] += 1
print(max(ans.values()))