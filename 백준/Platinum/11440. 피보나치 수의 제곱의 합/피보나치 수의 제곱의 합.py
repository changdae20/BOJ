import sys

N = int(sys.stdin.readline())

MOD = 1000000007

def mat_mul(a,b,MOD):
    return [[(a[0][0]*b[0][0] + a[0][1]*b[1][0])%MOD, (a[0][0]*b[0][1] + a[0][1]*b[1][1])%MOD],[(a[1][0]*b[0][0] + a[1][1]*b[1][0])%MOD,(a[1][0]*b[0][1] + a[1][1]*b[1][1])%MOD]]

def pow_mod(a,b,MOD):
    temp = list(a)
    ans = list(a)
    for char in bin(b)[2:][::-1]:
        if char=="1":
            ans = mat_mul(ans,temp,MOD)
            ans[0][0] %= MOD
            ans[0][1] %= MOD
            ans[1][0] %= MOD
            ans[1][1] %= MOD
        temp = mat_mul(temp,temp,MOD)
    return ans

result = pow_mod([[1,1],[1,0]],N,MOD)
print((result[1][1]*result[1][0])%MOD)