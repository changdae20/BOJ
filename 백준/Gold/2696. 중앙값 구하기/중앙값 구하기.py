import sys
import heapq

T = int(sys.stdin.readline())


for _ in range(T):
    N = int(sys.stdin.readline())

    max_heap = []
    min_heap = []
    num = []
    for _ in range((N-1)//10 + 1):
        num += list(map(int,sys.stdin.readline().split()))
    print(len(num)//2 + 1)
    for i in range(N):
        if len(max_heap)==0:
            heapq.heappush(max_heap, -num[i])
        elif len(max_heap)==len(min_heap) and num[i] <= -max_heap[0]:
            heapq.heappush(max_heap, -num[i])
        elif len(max_heap)==len(min_heap) and num[i] > -max_heap[0]:
            heapq.heappush(min_heap, num[i])
            heapq.heappush(max_heap, -heapq.heappop(min_heap))
        elif len(max_heap)>len(min_heap) and num[i] > -max_heap[0]:
            heapq.heappush(min_heap, num[i])
        elif len(max_heap)>len(min_heap) and num[i] <= -max_heap[0]:
            heapq.heappush(max_heap, -num[i])
            heapq.heappush(min_heap, -heapq.heappop(max_heap))
        
        if i%2==0: print(-max_heap[0],end=" ")
    print()