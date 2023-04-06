import sys
A,B = sys.stdin.readline().split()
print(max(int(A[::-1]),int(B[::-1])))