N,M,K = map(int,input().rstrip().split())
A = min(M,K)
B = min(N-M,N-K)
print(A+B)