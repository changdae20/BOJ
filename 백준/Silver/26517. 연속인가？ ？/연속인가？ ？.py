k = int(input().rstrip())
A,B,C,D = map(int,input().rstrip().split())
if(A*k+B == C*k+D):
    print("Yes",A*k+B)
else:
    print("No")