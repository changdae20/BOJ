import sys

def push(dic,word):
    a = dic
    for c in word:
        if c not in a.keys():
            a[c]={}
        a = a[c]
    a["end"]={}
    return

def ans(dic, word):
    count = 1
    a = dic[word[0]] # 첫 글자는 추론하지 않는다.

    for c in word[1:]:
        if(len(a)!=1):
            count += 1
        a = a[c]
    #print(count)
    return count


N=0
i=0
s=0
dic={}
words = []
for line in sys.stdin.readlines():
    if(N==0):
        N=int(line)
        dic={}
        words=[]
        i = 0
        s=0
    else:
        push(dic,line.strip())
        words.append(line.strip())
        i += 1

    if i==N:
        #print(dic)
        for word in words:
            #print(word,ans(dic,word))
            s += ans(dic,word)
        print(f"{round(s / N, 2):.2f}")
        #print(f"{s/N:.2f}")
        N=0