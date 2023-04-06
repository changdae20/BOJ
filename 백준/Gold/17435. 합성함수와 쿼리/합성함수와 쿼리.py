import sys

N = int(sys.stdin.readline())

f = list(map(int,sys.stdin.readline().split()))
data = []
data.append(list(f))

def append_to(num):
    global f
    while len(data)<num:
        data.append([data[-1][data[-1][x]-1] for x in range(N)])

K = int(sys.stdin.readline())

for _ in range(K):
    power, x = map(int,sys.stdin.readline().split())
    append_to(len(bin(power)[2:]))
    for bin_power, binary in enumerate(bin(power)[2:][::-1]):
        if binary=="1":
            x = data[bin_power][x-1]
    print(x)