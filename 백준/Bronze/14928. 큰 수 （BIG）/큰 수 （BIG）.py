a = input()
b = 0
for c in a:
    n = ord(c)-ord('0')
    b = (b*10 + n) % 20000303
print(b)