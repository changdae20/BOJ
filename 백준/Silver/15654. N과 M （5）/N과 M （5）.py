from itertools import permutations

M, N = map(int,input().split())
data = list(map(int,input().split()))
data.sort()

data = list(permutations(data,N))

for tup in data:
    for i in tup:
        print(i,end=" ")
    print("")