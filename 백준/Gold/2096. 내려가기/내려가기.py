import sys

N = int(sys.stdin.readline())

max_data = [0,0,0]
min_data = [0,0,0]

for i in range(0,N):
    data = list(map(int,sys.stdin.readline().split()))
    max0 = max(max_data[0],max_data[1]) + data[0]
    max1 = max(max_data[0],max_data[1],max_data[2]) + data[1]
    max2 = max(max_data[1],max_data[2]) + data[2]
    min0 = min(min_data[0],min_data[1]) + data[0]
    min1 = min(min_data[0],min_data[1],min_data[2]) + data[1]
    min2 = min(min_data[1],min_data[2]) + data[2]
    max_data = [max0,max1,max2]
    min_data = [min0,min1,min2]

print(max(max_data),min(min_data))