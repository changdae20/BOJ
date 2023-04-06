N = int(input())

if(N<=5): print(N)
elif(N%6==0): print(3*(N//6)*((N//6)+1)+1)
elif(N%6==1): print(3*(N//6)*((N//6)+1)+1 + (N//6))
else: print(3*(N//6)*((N//6)+1)+1 + (N//6) + ((N//6)+1)*((N%6)-1))