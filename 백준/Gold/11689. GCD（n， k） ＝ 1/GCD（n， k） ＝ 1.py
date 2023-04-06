import sys

N = int(sys.stdin.readline())

ans = N

for p in range(2, int(N**0.5)+1):
    if N % p == 0:
        ans = ans - ans//p
        while(N%p==0): N = N//p

if N>1 : ans = ans - ans//N

print(ans)