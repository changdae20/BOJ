import sys

N, K = map(int, sys.stdin.readline().split())

coins = []
count = 0
for _ in range(N):
    coins.append(int(sys.stdin.readline()))

for coin in coins[::-1]:
    count += (K//coin)
    K -= coin * (K//coin)
print(count)