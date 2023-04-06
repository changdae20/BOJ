def print_star(n,line):
    if(n==1):
        return "*"
    else:
        if(int(line//(n//3))==1):
            return print_star(n//3,line-(n//3))+(" "*(n//3))+print_star(n//3,line-(n//3))
        elif(int(line//(n//3))==2):
            return print_star(n//3,line-2*(n//3))*3
        else:
            return print_star(n//3,line)*3
n = int(input())
for i in range(0,n):
    print(print_star(n,i))