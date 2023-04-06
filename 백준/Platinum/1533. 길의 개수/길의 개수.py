import sys
MOD = 1000003
def mat_mul(A,B,MOD):
    global N
    res = [[0 for _ in range(5*N + 1)] for _ in range(5*N + 1)]

    for i in range(1,5*N + 1):
        for j in range(1,5*N + 1):
            for k in range(1,5*N + 1):
                res[i][j] += A[i][k] * B[k][j]
                res[i][j] %= MOD
    return res

N,S,E,T = map(int,sys.stdin.readline().split())

dist = [[0 for _ in range(5*N + 1)] for _ in range(5*N + 1)]

for i in range(1,N+1):
    dist[5*i-4][5*i-3]=1
    dist[5*i-3][5*i-2]=1
    dist[5*i-2][5*i-1]=1
    dist[5*i-1][5*i]=1
    d = map(int,sys.stdin.readline().replace("\n",""))
    for j, val in enumerate(d):
        if val==0: continue
        else:
            dist[5*i][5*j + 6 - val] = 1

ans = [list(dist[i]) for i in range(len(dist))]


for char in bin(T-1)[2:][::-1]:
    if char=="1":
        ans = mat_mul(ans,dist,MOD)
    dist = mat_mul(dist,dist,MOD)
print(ans[5*S][5*E])