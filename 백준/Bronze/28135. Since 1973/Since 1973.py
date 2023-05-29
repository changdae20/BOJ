cnt = 0
N = int(input())
for i in range(N):
    if "50" in str(i):
        cnt += 1
print(N+cnt)