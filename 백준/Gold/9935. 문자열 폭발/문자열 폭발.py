data = input()
explode = input()
len_explode = len(explode)
last = explode[-1]

answer = []

for ch in data:
    answer.append(ch)
    if ch==last and "".join(answer[-len_explode:])==explode:
        del answer[-len_explode:]

answer = "".join(answer)
if answer=="": print("FRULA")
else: print(answer)