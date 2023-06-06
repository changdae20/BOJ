import sys
N = int(sys.stdin.readline())
arr = sum(map(int,sys.stdin.readline().rstrip().split()))
total = arr + 8*(N-1)
print(total//24, total%24)
