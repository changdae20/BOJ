import sys

N = int(sys.stdin.readline())

l = 0
r = 10**400

while(l+1<r):
    mid = (l+r)//2
    if(mid*mid >= N): r = mid
    else: l = mid

print(r)