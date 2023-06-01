import sys
my = sys.stdin.readline().rstrip()
N = int(sys.stdin.readline().rstrip())
count = 0
for _ in range(N):
    if(sys.stdin.readline().rstrip() == my):
        count+=1

print(count)