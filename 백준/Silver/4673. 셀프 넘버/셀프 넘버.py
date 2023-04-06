import sys

ans = [False] * 10001

for i in range(1,10000):
    next = i + sum(int(x) for x in str(i))
    if next<=10000: ans[next]=True
    if ans[i]==False : print(i)