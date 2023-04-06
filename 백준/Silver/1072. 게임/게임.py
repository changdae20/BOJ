import sys

X, Y = map(int, sys.stdin.readline().strip().split())

cur = (Y*100)//X

if(cur == 100 or cur == 99):
    print(-1)
else:
    l = 0
    r = (X*X)//(99*X-100*Y) + 1

    while(l+1<r):
        mid = (l+r) // 2
        if cur == ((Y+mid)*100)//(X+mid):
            l = mid
        else:
            r = mid
    
    print(r)