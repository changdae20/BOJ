import sys

sys.setrecursionlimit(100000)

def solution(data,s,e):
    root = data[s]
    right_node = 0
    for idx in range(s+1,e+1):
        if(data[idx] > root):
            right_node = idx
            break
    left_node = s+1 if (s<e and s+1!=right_node) else 0
    
    if left_node!=0:
        solution(data,left_node,right_node-1 if right_node>0 else e)
    if right_node!=0:
        solution(data,right_node,e)
    print(root)


data = []
while True:
    try:
        data.append(int(input()))
    except:
        break

solution(data,0,len(data)-1)

