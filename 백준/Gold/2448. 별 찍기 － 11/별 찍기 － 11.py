import sys

stars = []

def print_once(i,text):
    stars.append(text)

    global N
    print(" " * (N-1-i) + text + " " * (N-1-i))

def print_twice(i, text):
    stars.append(text + " "*(2*i+1-len(text)*2) + text)

    global N
    print(" " * (N-1-i) + text + " "*(2*i+1-len(text)*2) + text + " " * (N-1-i))

N = int(sys.stdin.readline())
limit = 3
for i in range(N):
    if i==0:
        print_once(0,"*")
    elif i==1:
        print_once(1,"* *")
    elif i==2:
        print_once(2,"*****")
    else:
        print_twice(i,stars[i-limit//2])

    if i==limit-1:
        limit*=2