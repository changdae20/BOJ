import math
A,B = map(int,input().strip().split())
print((B-A)//int(math.gcd(B-A,B)), B//int(math.gcd(B-A,B)))