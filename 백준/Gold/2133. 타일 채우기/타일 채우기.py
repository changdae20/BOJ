import sys

N = int(sys.stdin.readline())

A = [0 for _ in range(N+1)]
B = [0 for _ in range(N+1)]

A[0] = 1
A[1] = 0

B[0] = 0
B[1] = 1

for i in range(2,N+1):
    A[i] = A[i-2] + B[i-1]*2
    B[i] = A[i-1] + B[i-2]

print(A[N])