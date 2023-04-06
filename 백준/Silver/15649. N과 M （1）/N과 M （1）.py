import sys
from itertools import permutations

N,M = map(int,sys.stdin.readline().split())

for t in permutations(range(N),M):
    print(" ".join([str(x+1) for x in t]))