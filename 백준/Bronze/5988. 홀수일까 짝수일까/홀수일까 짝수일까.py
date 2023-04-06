import sys
N = int(sys.stdin.readline().strip())

for _ in range(N):
    if sys.stdin.readline().strip()[-1] in ["1","3","5","7","9"]:
        print("odd")
    else:
        print("even")