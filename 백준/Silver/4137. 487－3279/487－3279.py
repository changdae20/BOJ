import sys

# A, B, and C map to 2
# D, E, and F map to 3
# G, H, and I map to 4
# J, K, and L map to 5
# M, N, and O map to 6
# P, R, and S map to 7
# T, U, and V map to 8
# W, X, and Y map to 9
def to_string(s):
    result = ""
    for c in s:
        if c=="-":
            continue
        if c in "ABC":
            result += "2"
        elif c in "DEF":
            result += "3"
        elif c in "GHI":
            result += "4"
        elif c in "JKL":
            result += "5"
        elif c in "MNO":
            result += "6"
        elif c in "PRS":
            result += "7"
        elif c in "TUV":
            result += "8"
        elif c in "WXY":
            result += "9"
        else:
            result += c
    return result

N = int(sys.stdin.readline().rstrip())
m = {}
for _ in range(N):
    s = sys.stdin.readline().rstrip()
    s = to_string(s)
    if s in m:
        m[s] += 1
    else:
        m[s] = 1

# sort by key
m = sorted(m.items(), key=lambda x: x[0])

if max(m, key=lambda x: x[1])[1] == 1:
    print("No duplicates.\n")
else:
    for k, v in m:
        if v > 1:
            print(k[:3] + "-" + k[3:] + " " + str(v))