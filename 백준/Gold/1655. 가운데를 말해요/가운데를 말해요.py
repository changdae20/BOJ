import sys
import heapq

N = int(sys.stdin.readline())

max_heap = []
min_heap = []

for _ in range(N):
    num = int(sys.stdin.readline())
    if len(max_heap)==0:
        heapq.heappush(max_heap, -num)
    elif len(max_heap)==len(min_heap) and num <= -max_heap[0]:
        heapq.heappush(max_heap, -num)
    elif len(max_heap)==len(min_heap) and num > -max_heap[0]:
        heapq.heappush(min_heap, num)
        heapq.heappush(max_heap, -heapq.heappop(min_heap))
    elif len(max_heap)>len(min_heap) and num > -max_heap[0]:
        heapq.heappush(min_heap, num)
    elif len(max_heap)>len(min_heap) and num <= -max_heap[0]:
        heapq.heappush(max_heap, -num)
        heapq.heappush(min_heap, -heapq.heappop(max_heap))
    
    print(-max_heap[0])