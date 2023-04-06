import sys

def solution():
    N, K = map(int,sys.stdin.readline().split(" "))
    cost = []
    ways = []
    parents = []
    complete = [False] * N
    pre = [0] * N
    queue = []
    ans = [0] * N
    cost = list(map(int,sys.stdin.readline().split(" ")))
    for i in range(N):
        ways.append([])
        parents.append([])
    for _ in range(K):
        first, second = map(int,sys.stdin.readline().split(" "))
        pre[second-1] += 1
        parents[second-1].append(first-1)
        ways[first-1].append(second-1)
    for i in range(N):
        if len(parents[i])==0:
            queue.append(i)
            ans[i]=cost[i]

    out = int(input())

    while(not complete[out-1]):
        complete[queue[0]] = True
        for node in ways[queue[0]]:
            pre[node] -= 1
            if pre[node]==0: queue.append(node)
            ans[node] = max(ans[node] , ans[queue[0]] + cost[node])
        del queue[0]

    print(ans[out-1])
    
for _ in range(int(sys.stdin.readline())):
    solution()
