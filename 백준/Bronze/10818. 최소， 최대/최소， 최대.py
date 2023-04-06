import sys
a = input()
l = list(map(int,sys.stdin.readline().strip().split()))
print(min(l),max(l))