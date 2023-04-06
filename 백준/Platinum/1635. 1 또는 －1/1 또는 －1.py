import sys
from itertools import combinations

def dot(a,b):
    return sum([a[i]*b[i] for i in range(len(a))])

N, M = map(int, sys.stdin.readline().split())

orig_A = []
A = []

for _ in range(M):
    temp = list(map(int, sys.stdin.readline().split()))
    orig_A.append(temp)
    temp = [x * temp[0] for x in temp]
    if temp not in A: A.append(temp)

for combi in combinations(range(N),N//2):
    B = []

    for ai in A:
        has_solution = False
        for bi in B:
            if(dot(ai,bi)==0):
                has_solution = True
                break
        if not has_solution:
            B.append([(ai[x] if x in combi else -ai[x]) for x in range(N)])
        if(len(B)>N): break
    if(len(B)>N): continue
    else:

        for ai in orig_A:
            for bi in B:
                if(dot(ai,bi)==0):
                    for bij in bi:
                        print(str(bij) + " ", end="")
                    print()
                    break
        break