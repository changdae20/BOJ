def factorial(n):
    if(n==0): return 1
    else : return n*factorial(n-1)
   

n, m = map(int,input().split())

print(factorial(n)//(factorial(m)*factorial(n-m)))