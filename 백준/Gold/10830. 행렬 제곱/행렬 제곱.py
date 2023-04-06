def mult(a,b,m,N):
    answer = [[0 for _ in range(N)] for _ in range(N)]
    
    for i in range(N):
        for j in range(N):
            answer[i][j] = sum([a[i][k]*b[k][j] for k in range(N)])%m
    return answer

            
N,B = map(int,input().split())
A = []
ans = []
for i in range(N):
    A.append(list(map(int,input().split())))
    ans.append([int(j==i) for j in range(N)])

bin_n = bin(B)[2:][::-1]
for i in range(len(bin_n)):
    if bin_n[i]=='1':
        ans = mult(ans,A,1000,N)
        A = mult(A,A,1000,N)
    elif bin_n[i]=='0':
        A = mult(A,A,1000,N)
    
for i in range(N):
    for j in range(N):
        print(ans[i][j],end=" ")
    print("")