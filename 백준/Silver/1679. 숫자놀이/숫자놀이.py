N = int(input())
numbers = list(map(int,input().split()))
limit = int(input())

def get_data(data,idx):
    if idx<0: return 2**31
    else : return data[idx]
    
data = [0,1]
i=2
while True:
    num = min([get_data(data,i-j) for j in numbers])
    if num>=limit: break
    else:
        data.append(num+1)
        i+=1
print("holsoon" if i%2==0 else "jjaksoon","win","at",i)