import sys
h = 1
arr = [[0 for _ in range(1025)] for _ in range(1025)]

N,M = map(int,sys.stdin.readline().split())

while(h<N): h = h<<1
tree = [[0 for _ in range(2*h)] for _ in range(2*h)]



def update(x,y,d):
    global h

    i=y+h-1
    j=x+h-1
    tree[i][j] = d
    while(j > 1):
	    j = j // 2
	    tree[i][j] = tree[i][j * 2] + tree[i][j * 2 + 1]
    while (i > 1):
        j = x + h - 1
        i = i // 2
        tree[i][j] = tree[i * 2][j] + tree[i * 2 + 1][j]
        while (j > 1):
            j = j // 2
            tree[i][j] = tree[i][j * 2] + tree[i][j * 2 + 1]
    return

def x_query(y, nodeL, nodeR, nodeNum, l, r):
	if (nodeL <= l and r <= nodeR): return tree[y][nodeNum]
	elif (nodeR < l or r < nodeL): return 0
	mid = (l+r)//2
	return x_query(y, nodeL, nodeR, nodeNum * 2, l, mid) + x_query(y, nodeL,nodeR, nodeNum * 2 + 1, mid+1, r)

def y_query(nodeL, nodeR, nodeNum, l, r, x1, x2):
	if (nodeL <= l and r <= nodeR): return x_query(nodeNum,x1,x2,1,1,h)
	elif (nodeR < l or r < nodeL): return 0
	mid = (l+r) // 2
	return y_query(nodeL, nodeR, nodeNum * 2, l, mid,x1,x2) + y_query(nodeL, nodeR, nodeNum * 2 + 1, mid+1, r,x1,x2)

for i in range(1,N+1):
    arr = list(map(int,sys.stdin.readline().split()))
    for j in range(1,N+1):
        update(i,j,arr[j-1])

for _ in range(M):
    query = list(map(int,sys.stdin.readline().split()))
    if(query[0]==0):
        update(query[1],query[2],query[3])
    elif(query[0]==1):
        query[1], query[3] = min(query[1],query[3]) ,max(query[1],query[3])
        query[2], query[4] = min(query[2],query[4]) ,max(query[2],query[4])
        print(y_query(query[2],query[4],1,1,h,query[1],query[3]))
 