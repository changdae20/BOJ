import math
def prime_until(num):
    a = [True] * (num+1)
    a[0]=a[1]=False
    for i in range(2,int(math.sqrt(num))+1):
        if(a[i]):
            for j in range(2*i,num+1,i):
                a[j]=False
    return a

a,b = map(int,input().split())

prime_list = prime_until(int(math.sqrt(b)))
count = 0

for i in range(0,len(prime_list)):
    if(prime_list[i]):
        j=2
        while (i**j) <= b:
            if a<=(i**j):count+=1
            j +=1
print(count)