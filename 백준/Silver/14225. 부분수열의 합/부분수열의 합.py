import sys
from itertools import combinations

N = int(sys.stdin.readline())
S = list(map(int,sys.stdin.readline().split()))

SET = set()
for i in range(1,N+1):
    for comb in combinations(range(N),i):
        SET.add(sum([S[idx] for idx in comb]))

for i in range(1,sum(S)+2):
    if i not in SET:
        print(i)
        break