A = int(input())
B = int(input())
C = int(input())

d = {}
for c in "0123456789":
    d[c]=0
for c in str(A*B*C):
    d[c]+=1
for i in range(0,10):
    print(d[str(i)])