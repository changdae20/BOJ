import heapq
import sys
heap = []

N = int(sys.stdin.readline())

for _ in range(N):
    num = int(sys.stdin.readline())
    if num>0: heapq.heappush(heap,num)
    else:
        try:
            print(heapq.heappop(heap))
        except:
            print(0)