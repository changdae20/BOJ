import math

N = int(input())
N -= 1
coefficients = [
    (1,16),
    (2,-16),
    (3,-8),
    (4,-16),
    (5,-4),
    (6,-4),
    (7,2)
]

val = 0

for (i,c) in coefficients:
    frac = 0
    for k in range(0,N+1):
        frac += pow(16,N-k,(8*k+i)**2)/((8*k+i)**2)
        frac = frac - int(frac)
    for k in range(N+1, 9999999):
        tmp = pow(16, float(N-k)) / ((8*k+i)**2)
        if(tmp < 1e-15): break
        frac += tmp
    val += c*frac

val = int((val - math.floor(val))*16)

print("0123456789ABCDEF"[val])