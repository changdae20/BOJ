import sys
from itertools import combinations

N = int(sys.stdin.readline())

def make_one_number(N):
    candidate = []
    for i in range(1,10):
        num = i
        count = 1
        for j in range(N):
            if(num%N==0):
                candidate.append(int(str(i) * count))
                break
            num = ((num*10) + i)%N
            count += 1
    if(len(candidate)): return min(candidate)
    else: return 0

def make_two_number(N):
    for i in range(1,99): # i 는 총 문자열의 수
        # print(i)
        candidate = []
        for j in range(2**(i-1),2**i): # j 는 문자열의 길이가 i인 경우의 수
            text = (bin(j)[2:]).zfill(i)
            text = text.replace("0","a")
            
            for combi in combinations(range(10),2):
                num = int(text.replace("1",str(combi[1])).replace("a",str(combi[0])))
                if(num>=N and num%N==0):
                    candidate.append(num)
                num2 = int(text.replace("1",str(combi[0])).replace("a",str(combi[1])))
                if(num2>=N and num2%N==0):
                    candidate.append(num2)
        if(len(candidate)): return min(candidate)

one = make_one_number(N)
if(one): print(one)
else: print(make_two_number(N))