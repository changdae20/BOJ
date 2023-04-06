def is_palindrome(str):
    for i in range(0,int((len(str)+1)/2)):
        if(str[i]!=str[len(str)-1-i]): return False
    return True

data = input()

for i in range(0,len(data)):
    if(is_palindrome(data[i:len(data)])):
        print(len(data)+i)
        break


