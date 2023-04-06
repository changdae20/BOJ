N, T = map(int,input().split())
bus = []

for i in range(N):
    bus.append(list(map(int,input().split())))

min_T = 2**31
for i in range(len(bus)):
    for time in range(bus[i][0],bus[i][0] + (bus[i][1]*bus[i][2]),bus[i][1]):
        if(time >= T and min_T>(time-T)):
            min_T = time-T
            break

if min_T == 2**31 : print(-1)
else: print(min_T)