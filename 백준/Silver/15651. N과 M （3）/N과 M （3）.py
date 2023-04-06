import sys

N, M = map(int,sys.stdin.readline().split())

for i in range(N**M):
    temp = i
    text = []
    for _ in range(M):
        text.append(str(temp%N + 1))
        temp = temp // N
    print(" ".join(text[::-1]))