import sys

N = int(sys.stdin.readline())

mu = [0] * int(2000000000000**0.5 + 1)
mu[1] = 1
def make_mu(n):
    for i in range(1,n+1):
        for j in range(2*i,n+1,i):
            mu[j] -= mu[i]

def nth(n):
    count = 0
    for i in range(1,int(n**0.5)+1):
        count += mu[i] * (n//(i**2))
    return n-count


make_mu(len(mu)-1)

start = 0
end = 2000000000000

while (start<end-1):
    mid = (start+end)//2
    if(nth(mid)<N): start = mid
    else: end = mid

print(end)