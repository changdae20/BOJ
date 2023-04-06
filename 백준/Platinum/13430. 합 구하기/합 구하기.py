import sys

K ,N = map(int,sys.stdin.readline().split())
MOD = 1000000007

first = 1

for i in range(N,N+K+1):
    first = (first * i) % MOD

second = 1

for i in range(1,K+2):
    second = (second * i) % MOD

print((first * pow(second,MOD-2,MOD))%MOD)