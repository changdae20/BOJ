N = int(input())
ans = ""
i = 1
while N>(2**i):
    N-=(2**i)
    i += 1

N -= 1

for j in range(1,i+1):
    ans = str(3*((N//(2**(j-1)))%(2)) + 4) + ans

print(ans)