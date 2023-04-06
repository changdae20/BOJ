import sys

def check_seq(seq):
    for i in range(1,len(seq)-1):
        if int(seq[i])*2 != int(seq[i-1])+int(seq[i+1]):
            return False
    return True

N = int(sys.stdin.readline())

count = 0
for i in range(1,N+1):
    count += check_seq(str(i))
print(count)