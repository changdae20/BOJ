def parse_binary(num):
    ret = ""
    i=0
    while(num>1):
        if(num%2==0):
            ret = ret + "0"
            num = num/2
        else:
            ret = ret + "1"
            num = (num-1)/2
    return ret + "1"

def count_ones(str):
    count = 0
    for i in range(0,len(str)):
        if(str[i]=="1"): count = count+1
    return count

def smallest_one(str):
    for i in range(0,len(str)):
        if(str[i]=="1"): return i

def bin_to_num(str):
    ans = 0
    for i in range(0,len(str)):
        ans = ans + (2**i)*int(str[i]=="1")
    return ans

N, K = input().split()
N = int(N)
K = int(K)

data = parse_binary(N)
ans = 0

while count_ones(data)>K:
    idx = smallest_one(data)
    ans = ans + 2**idx
    data = bin_to_num(data)
    data = data + 2**idx
    data = parse_binary(data)
    

print(ans)
