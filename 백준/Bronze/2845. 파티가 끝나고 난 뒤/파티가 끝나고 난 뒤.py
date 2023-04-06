import sys

A, B = map(int,sys.stdin.readline().strip().split())

N = list(map(int,sys.stdin.readline().strip().split()))

for i in N:
    print(i-(A*B),end=" ")