import sys

N = int(sys.stdin.readline())

A = [1,1,5]
B = [0,1,2]
C = [0,1,1]

def append_to(num):
    global A,B,C
    while len(A)<num+1:
        A.append(A[-1] + A[-2] + 2*B[-1] + C[-1])
        B.append(A[-2] + B[-1]) # since A was appended few ago!
        C.append(A[-2] + C[-2]) # since A was appended few ago!

for _ in range(N):
    K = int(sys.stdin.readline())
    try:
        print(A[K])
    except:
        append_to(K)
        print(A[K])