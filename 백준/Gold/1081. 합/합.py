import sys

def calc_sum(num):
    if num==-1: return 0
    count = 0
    for idx, char in enumerate(str(num)):
        if idx!=0:
            count += int(str(num)[:idx]) * 45 * (10**(len(str(num))-1-idx))
        count += sum(range(int(char))) * (10**(len(str(num))-1-idx))
        if idx!=len(str(num))-1:
            count += int(char) * (int(str(num)[idx+1:]) + 1)
        else:
            count += int(char)
    return count


A, B = map(int,sys.stdin.readline().split())
print(calc_sum(B)-calc_sum(A-1))
