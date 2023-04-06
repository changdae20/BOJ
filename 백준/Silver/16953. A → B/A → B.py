import heapq
A,B = map(int,input().split())

count = 0
while(B>A):
    if(B%2==0):
        B /= 2
        count +=1
    elif(B%10==1):
        B = B//10
        count +=1
    else: break
    
if(B==A):print(count+1)
else: print("-1")
    

