import sys

N = int(sys.stdin.readline().strip())

for _ in range(N):
    R,s = sys.stdin.readline().strip().split()
    for c in s:
        print(c*int(R),end="")
    print()