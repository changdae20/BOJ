def by_radix(ans, num):
    s = ""
    for idx, radix in enumerate(str(num)):
        if(idx>0):
            s = s + "+[" + ans[int(radix)] + "]"
        else:
            s = s + ans[int(radix)]
    return f"+[{s}]"

ans = {
    0 : "+![]",
    1 : "+!![]",
    2 : "!+[]+!+[]",
    3 : "!+[]+!+[]+!+[]",
    4 : "!+[]+!+[]+!+[]+!+[]",
    5 : "!+[]+!+[]+!+[]+!+[]+!+[]",
    6 : "!+[]+!+[]+!+[]+!+[]+!+[]+!+[]",
    7 : "+!![]+[+[]]-!![]-!![]-!![]",
    8 : "+!![]+[+[]]-!![]-!![]",
    9 : "+!![]+[+[]]-!![]",
    10 : "+[+!![]+[+[]]]"
}

for i in range(11,1001):
    s = by_radix(ans,i)
    ans[i] = s # Baseline : by_radix
    # 최소를 찾자
    if i%2==0 and (len(ans[i//2]) + 15)<=75: # 2의 배수인 경우 x*2 방법으로 우회 시도
        candidate = f"+[{ans[i//2]}]*[!+[]+!+[]]"
        if len(ans[i]) > len(candidate):
            ans[i] = candidate
    if i%3==0 and (len(ans[i//3]) + len(ans[3]) + 6)<=75: # 3의 배수인 경우
        candidate = f"+[{ans[i//3]}]*[{ans[3]}]"
        if len(ans[i]) > len(candidate):
            ans[i] = candidate
    if i%4==0 and (len(ans[i//4]) + len(ans[4]) + 6)<=75: # 4의 배수인 경우
        candidate = f"+[{ans[i//4]}]*[{ans[4]}]"
        if len(ans[i]) > len(candidate):
            ans[i] = candidate
    if i%5==0 and (len(ans[i//5]) + len(ans[5]) + 6)<=75: # 5의 배수인 경우
        candidate = f"+[{ans[i//5]}]*[{ans[5]}]"
        if len(ans[i]) > len(candidate):
            ans[i] = candidate
    if i%6==0 and (len(ans[i//6]) + len(ans[6]) + 6)<=75: # 6의 배수인 경우
        candidate = f"+[{ans[i//6]}]*[{ans[6]}]"
        if len(ans[i]) > len(candidate):
            ans[i] = candidate
    if i%7==0 and (len(ans[i//7]) + len(ans[7]) + 6)<=75: # 7의 배수인 경우
        candidate = f"+[{ans[i//7]}]*[{ans[7]}]"
        if len(ans[i]) > len(candidate):
            ans[i] = candidate
    if i%8==0 and (len(ans[i//8]) + len(ans[8]) + 6)<=75: # 8의 배수인 경우
        candidate = f"+[{ans[i//8]}]*[{ans[8]}]"
        if len(ans[i]) > len(candidate):
            ans[i] = candidate
    if i%9==0 and (len(ans[i//9]) + len(ans[9]) + 6)<=75: # 9의 배수인 경우
        candidate = f"+[{ans[i//9]}]*[{ans[9]}]"
        if len(ans[i]) > len(candidate):
            ans[i] = candidate
    if i%10==0 and (len(ans[i//10]) + len(ans[10]) + 6)<=75: # 10의 배수인 경우
        candidate = f"+[{ans[i//10]}]*[{ans[10]}]"
        if len(ans[i]) > len(candidate):
            ans[i] = candidate
    if (len(ans[int(i**0.5)]) + len(ans[i - int(i**0.5)**2]) + 25) <= 75: # x2 + y 꼴
        candidate = f"[+[{ans[int(i**0.5)]}]]**[+!![]+!![]]-[-[{ans[i - int(i**0.5)**2]}]]"
        if len(ans[i]) > len(candidate):
            ans[i] = candidate
    if (len(ans[i-1]) + 5) <= 75: # x + 1 꼴
        candidate = f"{ans[i-1]}+!+[]"
        if len(ans[i]) > len(candidate):
            ans[i] = candidate
    if (len(ans[i-2]) + 10) <= 75: # x + 2 꼴
        candidate = f"{ans[i-2]}+!+[]+!+[]"
        if len(ans[i]) > len(candidate):
            ans[i] = candidate
    if (len(ans[i-10]) + 14) <= 75: # x + 10 꼴
        candidate = f"{ans[i-10]}-[-!![]+[+[]]]"
        if len(ans[i]) > len(candidate):
            ans[i] = candidate

# x - y꼴 확인
for i in range(990,-1,-1):
    if (len(ans[int(i**0.5)+1]) + len(ans[(int(i**0.5)+1)**2 - i]) + 25) <= 75: # x2 - y 꼴
        candidate = f"[+[{ans[int(i**0.5)+1]}]]**[+!![]+!![]]-[+[{ans[(int(i**0.5)+1)**2 - i]}]]"
        if len(ans[i]) > len(candidate):
            ans[i] = candidate
    if (len(ans[i+1]) + 5) <= 75: # x - 1 꼴
        candidate = f"{ans[i+1]}-!-[]"
        if len(ans[i]) > len(candidate):
            ans[i] = candidate
    if (len(ans[i+2]) + 10) <= 75: # x - 2 꼴
        candidate = f"{ans[i+2]}-!-[]-!-[]"
        if len(ans[i]) > len(candidate):
            ans[i] = candidate
    if (len(ans[i+10]) + 14) <= 75: # x - 10 꼴
        candidate = f"{ans[i+10]}-[+!![]+[+[]]]"
        if len(ans[i]) > len(candidate):
            ans[i] = candidate
            
# 추가 우회 확인
for i in range(0,1001):
    for j in range(1,i//2):
        candidate = f"+[{ans[j]}]-[-{ans[i-j]}]"
        if len(ans[i]) > len(candidate):
            ans[i] = candidate

for i in range(11,1001):
    # 최소를 찾자
    if i%2==0 and (len(ans[i//2]) + 15)<=75: # 2의 배수인 경우 x*2 방법으로 우회 시도
        candidate = f"+[{ans[i//2]}]*[!+[]+!+[]]"
        if len(ans[i]) > len(candidate):
            ans[i] = candidate
    if i%3==0 and (len(ans[i//3]) + len(ans[3]) + 6)<=75: # 3의 배수인 경우
        candidate = f"+[{ans[i//3]}]*[{ans[3]}]"
        if len(ans[i]) > len(candidate):
            ans[i] = candidate
    if i%4==0 and (len(ans[i//4]) + len(ans[4]) + 6)<=75: # 4의 배수인 경우
        candidate = f"+[{ans[i//4]}]*[{ans[4]}]"
        if len(ans[i]) > len(candidate):
            ans[i] = candidate
    if i%5==0 and (len(ans[i//5]) + len(ans[5]) + 6)<=75: # 5의 배수인 경우
        candidate = f"+[{ans[i//5]}]*[{ans[5]}]"
        if len(ans[i]) > len(candidate):
            ans[i] = candidate
    if i%6==0 and (len(ans[i//6]) + len(ans[6]) + 6)<=75: # 6의 배수인 경우
        candidate = f"+[{ans[i//6]}]*[{ans[6]}]"
        if len(ans[i]) > len(candidate):
            ans[i] = candidate
    if i%7==0 and (len(ans[i//7]) + len(ans[7]) + 6)<=75: # 7의 배수인 경우
        candidate = f"+[{ans[i//7]}]*[{ans[7]}]"
        if len(ans[i]) > len(candidate):
            ans[i] = candidate
    if i%8==0 and (len(ans[i//8]) + len(ans[8]) + 6)<=75: # 8의 배수인 경우
        candidate = f"+[{ans[i//8]}]*[{ans[8]}]"
        if len(ans[i]) > len(candidate):
            ans[i] = candidate
    if i%9==0 and (len(ans[i//9]) + len(ans[9]) + 6)<=75: # 9의 배수인 경우
        candidate = f"+[{ans[i//9]}]*[{ans[9]}]"
        if len(ans[i]) > len(candidate):
            ans[i] = candidate
    if i%10==0 and (len(ans[i//10]) + len(ans[10]) + 6)<=75: # 10의 배수인 경우
        candidate = f"+[{ans[i//10]}]*[{ans[10]}]"
        if len(ans[i]) > len(candidate):
            ans[i] = candidate
    if (len(ans[int(i**0.5)]) + len(ans[i - int(i**0.5)**2]) + 25) <= 75: # x2 + y 꼴
        candidate = f"[+[{ans[int(i**0.5)]}]]**[+!![]+!![]]-[-[{ans[i - int(i**0.5)**2]}]]"
        if len(ans[i]) > len(candidate):
            ans[i] = candidate
    if (len(ans[i-1]) + 5) <= 75: # x + 1 꼴
        candidate = f"{ans[i-1]}+!+[]"
        if len(ans[i]) > len(candidate):
            ans[i] = candidate
    if (len(ans[i-2]) + 10) <= 75: # x + 2 꼴
        candidate = f"{ans[i-2]}+!+[]+!+[]"
        if len(ans[i]) > len(candidate):
            ans[i] = candidate
    if (len(ans[i-10]) + 14) <= 75: # x + 10 꼴
        candidate = f"{ans[i-10]}-[-!![]+[+[]]]"
        if len(ans[i]) > len(candidate):
            ans[i] = candidate

# x - y꼴 확인
for i in range(990,-1,-1):
    if (len(ans[int(i**0.5)+1]) + len(ans[(int(i**0.5)+1)**2 - i]) + 25) <= 75: # x2 - y 꼴
        candidate = f"[+[{ans[int(i**0.5)+1]}]]**[+!![]+!![]]-[+[{ans[(int(i**0.5)+1)**2 - i]}]]"
        if len(ans[i]) > len(candidate):
            ans[i] = candidate
    if (len(ans[i+1]) + 5) <= 75: # x - 1 꼴
        candidate = f"{ans[i+1]}-!-[]"
        if len(ans[i]) > len(candidate):
            ans[i] = candidate
    if (len(ans[i+2]) + 10) <= 75: # x - 2 꼴
        candidate = f"{ans[i+2]}-!-[]-!-[]"
        if len(ans[i]) > len(candidate):
            ans[i] = candidate
    if (len(ans[i+10]) + 14) <= 75: # x - 10 꼴
        candidate = f"{ans[i+10]}-[+!![]+[+[]]]"
        if len(ans[i]) > len(candidate):
            ans[i] = candidate

# 마지막 출력
for i in range(0,1001):
    print(ans[i])