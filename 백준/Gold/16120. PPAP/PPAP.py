import sys

data = sys.stdin.readline().strip()
explode = "PPAP"
len_explode = len(explode)
last = explode[-1]

answer = []

for ch in data:
    answer.append(ch)
    if ch==last and "".join(answer[-len_explode:])==explode:
        del answer[-len_explode+1:]

answer = "".join(answer)
if answer=="P": print("PPAP")
else: print("NP")