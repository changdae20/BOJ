a,b = map(int,input().split())

plus_one = a%b
orig = (b)-(a%b)

q = a//b
print((q**orig)*((q+1)**plus_one))