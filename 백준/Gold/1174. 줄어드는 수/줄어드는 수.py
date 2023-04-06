def factorial(n):
    if n==0:
        return 1
    else:
        return n*factorial(n-1)

def choose(n,r):
    if r<0 : return 0
    else: return factorial(n)/(factorial(r)*factorial(n-r))

def calc(N):
    if(N>=2**10): return -1
    elif(N==1): return 0
    N -= 1
    ans = ""
    radix = 0

    for i in range(9,-1,-1):
        if N>choose(10,i):
            N -= choose(10,i)
        else:
            N = choose(10,i) - N
            radix = 10-i
            break

    n = 9
    r = radix
    if(N==0):
        for i in range(radix,-1,-1):
            ans += str(i)
        return ans
    while N>0:
        if(N==1 and r==0):
            break
        if N<= choose(n,r-1):
            ans += str(n)
            n -= 1
            r -= 1
        else:
            N -= choose(n,r-1)
            n -= 1

    return ans

N = int(input())
print(calc(N))