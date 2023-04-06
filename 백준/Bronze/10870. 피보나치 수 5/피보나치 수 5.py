def mult(a,b,m):
    return [[(a[0][0]*b[0][0]+a[0][1]*b[1][0])%m,(a[0][0]*b[0][1]+a[0][1]*b[1][1])%m],[(a[1][0]*b[0][0]+a[1][1]*b[1][0])%m,(a[1][0]*b[0][1]+a[1][1]*b[1][1])%m]]

a = [[1,1],[1,0]]
tmp = [[1,1],[1,0]]
n = int(input())
bin_n = bin(n)[2:][::-1]
for i in range(len(bin_n)):
    if i==0 and bin_n[i]=='1':
        tmp = mult(tmp,tmp,1000000)
    elif i==0 and bin_n[i]=='0':
        a = [[1,0],[0,1]]
        tmp = mult(tmp,tmp,1000000)
    elif bin_n[i]=='0':
        tmp = mult(tmp,tmp,1000000)
    else:
        a = mult(a,tmp,1000000)
        tmp = mult(tmp,tmp,1000000)

print(a[0][1])