import sys

while True:
    s = sys.stdin.readline().rstrip().lower()
    if(s=="#"):
        break
    print(s.count("a")+s.count("e")+s.count("i")+s.count("o")+s.count("u"))