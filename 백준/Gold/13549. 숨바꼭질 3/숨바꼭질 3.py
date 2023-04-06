X, Y = map(int,input().split())

visited = [False] * 100001
q = [(X,0)]
answer = 0
while len(q)>0:
    popped = q[0] # Popped node
    if(popped[0]==Y):
        answer = popped[1]
        break
    q = q[1:] # Pop the queue
    visited[popped[0]]=True
    if popped[0]*2 <= 100000:
        if visited[popped[0]*2]==False:
            q = [(popped[0]*2,popped[1])] + q
    if popped[0]+1 <= 100000:
        if visited[popped[0]+1]==False:
            q.append((popped[0]+1,popped[1]+1))
    if 0 <= popped[0]-1:
        if visited[popped[0]-1]==False:
            q.append((popped[0]-1,popped[1]+1))
print(answer)