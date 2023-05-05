import sys

s = sys.stdin.readline().rstrip()

v = {}
for i in range(26):
    v[chr(ord('a') + i)] = 0

for c in s:
    v[c] += 1

print(" ".join(map(str, v.values())))