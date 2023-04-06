import math

def mod(list_,c):
    ans = 1
    for i in range(0,len(list_)):
        ans = ans * list_[i]
        if(ans>=c):
            ans = ans%c
    return ans
    

a,b,c = input().split()

a = int(a)
b = int(b)
c = int(c)

if(a>=c): a = a%c

remainder = []


while True:
    if(a==0):
        a=c
        b=1
        break
    if(a==1):
        b=1
        break
    quot = int(math.log(c,a)) + 1
    if(quot>b): break
    remainder = remainder + ([a] * (b%quot))
    a = mod([a]*quot,c)
    b = int(b/quot)


print (mod([a]*b + remainder,c))
