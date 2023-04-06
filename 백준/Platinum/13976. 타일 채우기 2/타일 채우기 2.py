import sys
MOD = 1000000007
def mat_mul(a,b,MOD): # 2 by 2 행렬 계산
    return [[(a[0][0]*b[0][0] + a[0][1]*b[1][0])%MOD, (a[0][0]*b[0][1] + a[0][1]*b[1][1])%MOD],[(a[1][0]*b[0][0] + a[1][1]*b[1][0])%MOD,(a[1][0]*b[0][1] + a[1][1]*b[1][1])%MOD]]

N = int(sys.stdin.readline())

if(N&1):print(0)
else:
    temp = [[4,-1],[1,0]]
    ans = [[1,0],[0,1]]
    for char in bin((N-2)//2)[2:][::-1]:
        if char=="1":
            ans = mat_mul(ans,temp,MOD)
        temp = mat_mul(temp,temp,MOD)
    print((ans[0][0]*3 + ans[0][1]*1)%MOD)