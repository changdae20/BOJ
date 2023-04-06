import sys

N = int(sys.stdin.readline())

degree = [0] * (N+1)
edge = []
for _ in range(N-1):
    first, second = map(int, sys.stdin.readline().split())
    edge.append([first, second])
    degree[first] += 1
    degree[second] += 1



G = 0
D = 0

for node in range(1,N+1): G += (degree[node] * (degree[node]-1) * (degree[node]-2))//6
for e in edge:
    D += (degree[e[0]]-1) * (degree[e[1]]-1)

# result
if D > 3*G: print("D")
elif D < 3*G: print("G")
else: print("DUDUDUNGA")