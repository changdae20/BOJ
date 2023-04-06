N = int(input())
a,b,c,d,e,f = input().split()
a = int(a)
b = int(b)
c = int(c)
d = int(d)
e = int(e)
f = int(f)

num = [a,b,c,d,e,f]
num2 = [a+b,a+d,a+e,a+c,b+d,d+e,c+e,b+c,f+d,f+b,f+c,f+e]
num3 = [a+b+d,a+b+c,a+e+c,a+d+e,f+d+b,f+b+c,f+e+d,f+e+c]
num.sort()
num2.sort()
num3.sort()


if(N==1):
    print(num[0]+num[1]+num[2]+num[3]+num[4])
else:
    once = 6* ((N-2)**2)
    twice = (N-2)*12
    triple = 8

    triple = triple - 4
    twice = twice + 4
    twice = twice - 4*(N-2)
    once = once + 4*(N-2)
    once = once - (N-2)**2

    print(once*num[0] + twice*num2[0] + triple*num3[0])
