import sys
import heapq

MAX = 9999999999
V,E = map(int,sys.stdin.readline().split())
s = int(sys.stdin.readline())
cost = [{} for _ in range(V)]
answer = [MAX] * V

    
for i in range(E):
    start,end,weight = map(int,sys.stdin.readline().split())
    try:
        cost[start-1][end-1] = min(cost[start-1][end-1], weight)
    except:
        cost[start-1][end-1] = weight

answer[s-1] = 0

queue = []
heapq.heappush(queue, [0, s-1])

while(len(queue)):
    node_distance, node_index = heapq.heappop(queue)
    
    if answer[node_index] < node_distance: continue
    
    for next in cost[node_index].keys():
        dist = node_distance + cost[node_index][next]
        if dist < answer[next]:
            answer[next] = dist
            heapq.heappush(queue, [dist, next])


for ans in answer:
    if ans==MAX: print("INF")
    else: print(ans)