import sys
MOD = 1000000007
N, K = map(int, sys.stdin.readline().split())

f = [1] * 1001
fac = [1] * 1002
f[0] = N % MOD
f[1] = ((N * (N+1))//2) % MOD

for i in range(1,1002):
    fac[i] = i * fac[i-1]


for k in range(2,K+1):
    ans = pow(N+1,k+1,MOD) - 1
    for p in range(0,k):
        ans = (ans  - ((fac[k+1]//fac[p])//fac[k+1-p])*f[p]) % MOD
    ans = (ans * pow(k+1,MOD-2,MOD)) % MOD
    f[k] = ans

print(f[K])