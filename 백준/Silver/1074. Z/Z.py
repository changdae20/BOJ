def quad_to_num(str):
    num = 0
    for i in range(0,len(str)):
        num = num + (4**i)*int(str[i])
    return num

def get_radix(N,r,c):
    radix = 0
    if(r>=2**(N-1)):
        radix = radix + 2
        r = r - 2**(N-1)
    if(c>=2**(N-1)):
        radix = radix + 1
        c = c - 2**(N-1)
    return radix,r,c

N, r, c = input().split()

N = int(N)
r = int(r)
c = int(c)
quad = ""
while(N>0):
    radix,r,c = get_radix(N,r,c)
    quad = str(radix) + quad
    N=N-1
print(quad_to_num(quad))
