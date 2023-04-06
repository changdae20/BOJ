import sys
def mod_pow(a,b,MOD): #calculate a^b mod MOD
    temp = a
    ans = 1
    for char in bin(b)[2:][::-1]:
        if char=="1": ans = (ans * temp) % MOD
        temp = (temp**2) % MOD
    return ans

def check(n,p,d,r):
    x = pow(p,d,n)
    if x==1 or x==n-1:
        return False
    
    for s in range(1,r):
        x = (x*x) % n
        if x==n-1:
            return False
    return True

def isPrime(N):
    if N<2: return False
    r = 0
    x = N-1
    while x>1 and x%2==0:
        r += 1
        x = x//2
    for p in [2,3,5,7,11,13,17,19,23,29,31]:
        if N==p: return True
        elif check(N,p,x,r): return False
    return True

T = int(sys.stdin.readline())
ans = 0
for _ in range(T):
    ans += int(isPrime(2*int(sys.stdin.readline()) + 1))

print(ans)