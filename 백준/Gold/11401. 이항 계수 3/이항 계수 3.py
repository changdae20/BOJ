import sys

N,K = map(int, sys.stdin.readline().split())

MOD = 1000000007

N_pac, K_pac, N_K_pac = 0,0,0
temp = 1
for i in range(0,N+1):
    temp = (temp * i if i!=0 else 1) % MOD
    if i==(N-K):
        N_K_pac = temp
    if i==K:
        K_pac = temp
    if i==N:
        N_pac = temp

def new_pow(a,b,MOD): #calculate a^b mod MOD
    temp = a
    ans = 1
    for char in bin(b)[2:][::-1]:
        if char=="1": ans = (ans * temp) % MOD
        temp = (temp**2) % MOD
    return ans
print((N_pac * new_pow(N_K_pac*K_pac,MOD-2,MOD))%MOD)