import sys
for line in sys.stdin.readlines():
    A, B = map(int, line.split())
    print(A+B)