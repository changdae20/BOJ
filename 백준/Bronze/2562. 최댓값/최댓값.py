import sys
arr = []

for _ in range(9):
    arr.append(int(sys.stdin.readline()))
        
(max, max_idx) = max([(a,b) for (b,a) in enumerate(arr)])
print(max)
print(max_idx+1)