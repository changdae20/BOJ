a = int(input())
b = int(input())

if a==1 or a==5:
    print(b*8 + (a-1))
else:
    print((b//2)*8 + (b%2)*4 + ((5-a) if (b%2==1) else (a-1)))