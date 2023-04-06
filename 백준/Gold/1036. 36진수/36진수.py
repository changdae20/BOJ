def toDec(str):
    if str=="0": return 0
    num = 0
    str = str[::-1]
    for i in range(len(str)):
        num += (36**i) * (int(str[i]) if str[i] in ['0','1','2','3','4','5','6','7','8','9'] else ord(str[i])-55)
    return num

def to36(num):
    if(num==0): return "0"
    ans = ""
    while num>0:
        tmp = num%36
        ans = (str(tmp) if tmp<10 else chr(tmp+55)) + ans
        num = num//36
    return ans

def single_add(a,b,c):
    res = toDec(a) + toDec(b) + c
    return res//36, to36(res%36)

def add(a,b):
    ans = ""
    a = a[::-1]
    b = b[::-1]
    
    carry, res = single_add(a[0],b[0],0)
    ans += res
    is_b_longer = len(b)-len(a)
    for i in range(1,min(len(a),len(b))):
        carry, res = single_add(a[i],b[i],carry)
        ans += res
    if(is_b_longer>0): #b가 더 긴 경우
        for j in range(len(a),len(b)):
            carry, res = single_add('0',b[j],carry)
            ans += res
        if carry!=0: ans+=str(carry)
    elif(is_b_longer==0): #a와 b가 같은길이
        if carry!=0: ans+=str(carry)
    else:
        for j in range(len(b),len(a)):
            carry, res = single_add('0',a[j],carry)
            ans += res
        if carry!=0: ans+=str(carry)
    return ans[::-1]

def compare(a,b):
    if(len(a)==len(b)):
        if(a[0]==b[0]): return compare(a[1:],b[1:])
        else: return ord(b[0])-ord(a[0])
    else: return len(b)-len(a)

def choose(arr):
    if(len(arr)==0): return "-"
    scores = {}
    for i in range(len(arr)):
        for j in range(len(arr[i])):
            if arr[i][::-1][j] in scores.keys(): scores[arr[i][::-1][j]] += (35 - toDec(arr[i][::-1][j]))*(36**j)
            else : scores[arr[i][::-1][j]] = (35 - toDec(arr[i][::-1][j]))*(36**j)
    res = sorted(scores.items(),key=(lambda x : x[1]),reverse=True)
    return res[0][0] if res[0][1]>0 else "-"
    
N = int(input())
num = []
for i in range(N):
    num.append(input())
K = int(input())

while K>0:
    repl = choose(num)
    if repl=="-": break
    for i in range(len(num)):
        num[i] = num[i].replace(repl,"Z")
    K-=1

ans = num[0]
for i in range(1,len(num)):
    ans = add(ans,num[i])
print(ans)