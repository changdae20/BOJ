data = input()
stack = []
idx=0
while idx<len(data):
    if data[idx] not in ["+","-","*","/","(",")"]: print(data[idx],end="")
    elif data[idx] in ["+","-","*","/"]:
        if len(stack)>0:
            if stack[len(stack)-1]=="(":
                stack.append(data[idx])
            elif data[idx] in ["*","/"] and stack[len(stack)-1] in ["+","-"]:
                stack.append(data[idx])
            else:
                print(stack.pop(),end="")
                idx -= 1
        else:
            stack.append(data[idx])
    elif data[idx]=="(": stack.append("(")
    elif data[idx]==")":
        popped = stack.pop()
        while popped!="(" and len(stack)>0:
            print(popped,end="")
            popped = stack.pop()
    idx +=1

for char in stack[::-1]:
    print(char,end="")
        