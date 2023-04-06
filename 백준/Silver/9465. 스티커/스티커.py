def solution(N,up,down):
    up_solution = [0] * (N+1)
    down_solution = [0] * (N+1)
    
    up_solution[0] = 0
    down_solution[0] = 0
    
    up_solution[1] = up[0]
    down_solution[1] = down[0]
    
    for i in range(2,N+1):
        up_solution[i] = max(down_solution[i-1],down_solution[i-2]) + up[i-1]
        down_solution[i] = max(up_solution[i-1],up_solution[i-2]) + down[i-1]
        
    return max(up_solution[-1],down_solution[-1])

T = int(input())

for t in range(T):
    N = int(input())
    up = list(map(int,input().split()))
    down = list(map(int,input().split()))
    print(solution(N,up,down))
    
