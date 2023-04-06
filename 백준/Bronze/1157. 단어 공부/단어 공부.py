import sys

d = {}
for i in range(65,65+26):
    d[chr(i)]=0
for c in sys.stdin.readline().strip():
    d[c.upper()] += 1

s = sorted(d.items(), key = lambda item: item[1], reverse = True)
if len(s)>1 and s[0][1]==s[1][1]:
    print("?")
else:
    print(s[0][0])